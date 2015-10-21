/*
 This program is recieve the color data from the 'keyinput.txt' and generate the 'hash index' of each value, insert it into correct position of a hash table..
 Hash table is a struct array in size 33, and each struct is consist of character array for 'color data'  and pointer for over flow chaining
 
 After generate a hash table and insert, search, delete, save the all value of hash table into a 'hashresult.txt' file.
 
 
 2014/05/16, Made by 우영남.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct bucket bucket;
struct bucket{ // It is struct for bucket
    char color_data[20];
    bucket* overflow_ptr;
};

int char2dec(char* string_data); // function declaration of 'char2dec'
char* dec2bin(int int_data);// function declaration of 'dec2bin'
int mid_square(char* char_arr);// function declaration of 'mid_square'
int hash(int number);// function declaration of 'hash'
void insert(char* input_data, int index);// function declaration of 'insert'

void printAll();// function declaration of 'printAll'
void search(char* search_data);// function declaration of 'search'
void delete(char* delete_data);// function declaration of 'delete'
char* itoa(int int_data);// function declaration of 'itoa'


bucket hash_table[33]; // hash table..

int main(void){
    char readFile_name[20] = "keyinput.txt";
    char writeFile_name[20] = "hashresult.txt";
    
    FILE* readFile;
    FILE* writeFile;
    
    char temp_line[20];
    char* char_arr;
    int hash_index, temp_index, i;
    
    //initialize the 'hash_table'..
    for(i=0; i<33; i++){
        strcpy(hash_table[i].color_data,"NULL");
    }
    
    
    readFile = fopen(readFile_name, "r");
    writeFile = fopen(writeFile_name, "w");
    
    //if file open fail, print the error message..
    if(readFile == NULL || writeFile == NULL){
        printf("FILE OPEN ERROR!\n");
        return 0;
    }
    
    //read data from the file and hashing it and generate the index..
    while(fscanf(readFile, "%s", temp_line)!=EOF){
        char_arr = dec2bin(char2dec(temp_line));
        temp_index = mid_square(char_arr);
        hash_index = hash(temp_index);
        
        insert(temp_line, hash_index);
    }
    
    
    //print the contents of the hash table
    printf("<<1.Current data>>\n");
    printAll();
    printf("\n\n");
    
    //Search for DarkBrown, Blue, Purple
    printf("<<2.Search for DarkBrown / Blue / Purple>>\n");
    search("DarkBrown");
    search("Blue");
    search("Purple");
    printf("\n\n");
    
    //Delete Purple, Blue, Golden
    printf("<<3.Delete for Purple / Blue / Golden>>\n");
    delete("Purple");
    delete("Blue");
    delete("Golden");
    printf(" - RESULT - \n");
    printAll();
    printf("\n\n");
    
    //Insert the three data
    printf("<<4.Insert DarkBrown / White / Golden>>\n");
    printf("1)Insert DarkBrown\n");
    printf(" - Hash index of DarkBrown : %d\n",hash(mid_square(dec2bin(char2dec("DarkBrown")))));
    insert("DarkBrown",hash(mid_square(dec2bin(char2dec("DarkBrown")))));

    printf("2)Insert White\n");
    printf(" - Hash index of White : %d\n",hash(mid_square(dec2bin(char2dec("White")))));
    insert("White",hash(mid_square(dec2bin(char2dec("White")))));

    printf("3)Insert Golden\n");
    printf(" - Hash index of DarkBrown : %d\n",hash(mid_square(dec2bin(char2dec("Golden")))));
    insert("Golden",hash(mid_square(dec2bin(char2dec("Golden")))));

    printf("4)Insert!!\n");

    printAll();
    printf("\n\n");
    
    //Search for DarkBrown, Blue, Golden, Yellow, Silver
    printf("<<5.Search for DarkBrown / Blue / Golden / Yellow / Silver>>\n");
    search("DarkBrown");
    search("Blue");
    search("Golden");
    search("Yellow");
    search("Silver");
    printf("\n\n");
    
    
    //write the contents of the final hash table(including the overflow) into 'hashresult.txt'
    for(i=0; i<33; i++){
        bucket* current = &hash_table[i];
        fprintf(writeFile,"%s",current->color_data);
        current = current->overflow_ptr;
        
        while(current){
            
            fprintf(writeFile,"->%s",current->color_data);
            
            current = current->overflow_ptr;
        }
        fprintf(writeFile, "\n");
    }

    
    //file close
    fclose(readFile);
    fclose(writeFile);
    
    printf("[PROGRAM TERMINATED]\n");
}


/*
 This function recieve the delete color name and delete it from the hash table.
 
 It consider three case of a delete.
 
 1. If delete data have overflow chaining.
 2. If delete data is in the overflow chaining.
 3. If delete data is end of the overflow chaining.
 
 If there is no delete data in hash table, print the delete fail message.
 
 Input : delete data
 Output : none
 */
void delete(char* delete_data){
    int i;
    bucket* prev = NULL;
    
    for(i=0; i<33; i++){
        
        bucket* current = &hash_table[i];
        while(current){
            if(strcmp(current->color_data,delete_data)==0){
                if(prev){//If delete data is in the overflow chaining.
                    if(current->overflow_ptr){
                        prev->overflow_ptr = current->overflow_ptr;
                    }
                    prev->overflow_ptr = NULL;
                    free(current);
                    printf("<DEL : %s!>\n",delete_data);
                }
                
                else{
                    if(current->overflow_ptr){//If delete data have overflow chaining.
                        strcpy(current->color_data,current->overflow_ptr->color_data);
                        if(current->overflow_ptr->overflow_ptr){
                            current->overflow_ptr = current->overflow_ptr->overflow_ptr;
                        }
                        free(current->overflow_ptr);
                        current->overflow_ptr = NULL;
                    }
                    else{//If delete data is end of the overflow chaining.
                        strcpy(current->color_data, "NULL");
                    }
                    
                    printf("<DEL : %s!>\n",delete_data);
                    return;
                }
                
            }
            prev = current;
            current = current->overflow_ptr;
        }
        prev = NULL;
    }
    printf("<FAIL : '%s' not exist>\n",delete_data);

}

/*
 It is search the 'search data' from hash table.
 
 If search success, print the index of a data.
 
 But search fail, print the 'not exist' message.
 
 Input : search data
 Output : none
 */
void search(char* search_data){
    int i=0;
    
    for(i=0; i<33; i++){
        
        bucket* current = &hash_table[i];
        while(current){
            if(strcmp(current->color_data,search_data)==0){
                printf("<exist in '%d'index!>\n", i);
                return;
            }
            
            current = current->overflow_ptr;
        }
    }
    
    printf("<not exist!>\n");
}

/*
 
 It is print all data in hash table.
 
 Input : none
 Output : none
 */
void printAll(){
    int i;
    
    for(i=0; i<33; i++){
        bucket* current = &hash_table[i];
        printf("[%s]",current->color_data);
        current = current->overflow_ptr;
        
        while(current){
            printf("->[%s]",current->color_data);
            current = current->overflow_ptr;
        }
        printf("\n");
    }
}

/*
 
 It is insert the color data in corret index.
 
 If insert bucket was already occupied, generate the overflow chaining and save the data in it.
 
 Input : input color data, index
 Output : none
 */
void insert(char* input_data, int index){
    //if bucket is already occupied..
    if(strcmp(hash_table[index].color_data,"NULL")!=0){
        if(strcmp(hash_table[index].color_data,input_data)==0){
            printf("  - <'%s' Already exist!>\n\n",input_data);
            return;
        }
        bucket* current = &hash_table[index];
        bucket* prev = NULL;
        
        bucket* new_bucket = (bucket*)malloc(sizeof(bucket)*1);
        strcpy(new_bucket->color_data, input_data);
        
        while(current){
            prev = current;
            current = current->overflow_ptr;
        }
        
        if(prev){
            prev->overflow_ptr = new_bucket;
        }
    }
    
    //bucket is empty..
    else if(strcmp(hash_table[index].color_data,"NULL")==0){
        strcpy(hash_table[index].color_data,input_data);
    }
    
    
}

/*
 
 It is generate the final hash index by modulo 33.
 
 return value will be used in hash index.
 
 Input : number
 Output : modulo 33
 */
int hash(int number){
    return number%33;
}

/*
 
 It generate the integer of four chipers.
 
 This function use the 'atoi' function.
 
 Input : character array
 Output : middle 4 digits in the input array
 */
int mid_square(char* char_arr){
    int result=0;
    char temp_result[5];
    int i;

    
    for(i=0; i<4; i++){
        temp_result[i] = char_arr[i+2];
    }
    
    result = atoi(temp_result);
    return result;
}

/*
 It recieve the integer number and convert it to chacter array.
 
 Input : integer number
 Output : character array
 */
char* itoa(int int_data){
    int data = int_data;
    char* result_charArr;
    int size=0;
    int i;
    
    while(data!=0){
        size++;
        data = data/10;
    }
    
    result_charArr = (char*)malloc(sizeof(char)*size);
    
    for(i=size-1; i>=0; i--){
        result_charArr[i] = (char)(int_data%10 + 48);
        int_data = int_data/10;
    }
    
    return result_charArr;
}

/*
 It is square the input decimal number and convert the result to a character array.
 
 It use the 'itoa'function.
 
 Input : decimal number
 Output : character array
 */
char* dec2bin(int int_data){
    char* result_arr = (char*)malloc(sizeof(char)*33);
    char* temp_result;
    int i;
    
    int squared = int_data*int_data;
    
    temp_result = itoa(squared);
    
    for(i=0; i<33; i++){
        result_arr[i] = NULL;
    }
    
    for(i=0; i<strlen(temp_result); i++){
        result_arr[i] = temp_result[i];
    }
    
    return result_arr;
}

/*
 
 It is convert the each character of a array to a decimal number.
 
 It use the 'atoi' function.
 
 Each decimal number corresponding to its position in English alphabet.
 
 It is not consider lower case or upper case.
 
 Input : character array
 Output : integer number
 */
int char2dec(char* string_data){
    int result=0;
    
    int sizeOfString = (int)strlen(string_data);
    char resultArr[5];
    int temp_int=0;
    int temp_modulo=0;
    
    int i;
    int k=3;
    
    
    for(i=sizeOfString-1; i>=0; i--){
        if(65<=string_data[i] && string_data[i]<=90){ // if character is upper case
            temp_int = string_data[i]-'A'+1;
        }
        else if(97<=string_data[i] && string_data[i]<=122){ // if character is lower case
            temp_int = string_data[i]-'a'+1;
        }
        
        if(0<=temp_int && temp_int<=9){
            resultArr[k] = (char)temp_int+48;
            k--;
            if(k==-1){
                break;
            }
        }
        else if(9<temp_int){
            temp_modulo = temp_int%10;
            resultArr[k] = (char)temp_modulo+48;

            k--;
            if(k==-1){
                break;
            }
            temp_modulo = temp_int/10;
            resultArr[k] = (char)temp_modulo+48;

            k--;
            if(k==-1){
                break;
            }
        }
    }

    result = atoi(resultArr);
    
    return result;
}