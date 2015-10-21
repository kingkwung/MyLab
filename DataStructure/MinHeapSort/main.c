/*
 This program read the file and sort them in name ascending order using min heap sort.
 And store it into another file.
 
 input : File "input.txt"
 ouput : File "result2.txt"
 
 2014/06/08 made by Woo youngnam
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(x,y,t) ( (t)=(x),(x)=(y),(y)=(t))
#define size 44

//struct for person information
typedef struct person person;
struct person {
    char name[20];
    int age;
};
person p[size];

//funcgiont declarations
void insert(char* readLine, int index);
void adjusting(person* p, int root, int n);
void minHeapSort(person* p, int n);

//main function
int main(void){
    FILE* readFile;
    FILE* writeFile;
    
    int i;
    int index;
    
    char readFile_name[20] = "input.txt";
    char writeFile_name[20] = "result2.txt";
    char readLine[30];
    
    readFile = fopen(readFile_name, "r");
    writeFile = fopen(writeFile_name, "w");
    
    //file open
    if(readFile == NULL || writeFile == NULL){
        printf("[ERROR]file open error");
        return 0;
    }
    
    index=1;
    while(fscanf(readFile, "%s", readLine)!=EOF){
        insert(readLine, index); // read the text file and send it into function "insert"
        index++;
    }
    
    
    minHeapSort(p, index-1);//call the minHeapSort function
    
    printf("[RESULT]\n");
    for(i=size; i>0; i--){
        printf("%s|%d\n",p[i].name, p[i].age);
        
        fprintf(writeFile,"%s|%d\n",p[i].name, p[i].age);//write the sorted structs into a file
    }
    
    fclose(readFile);
	fclose(writeFile);
    printf("\n[PROGRAM TERMINATED]\n");
}

/*
 It is rearrange the struct array correctly.
 
 input : person struct array, index of root, list size
 output :none.
 */
void adjusting(person* p, int root, int n){
    char root_key[20];
    int child;
    person temp_p;
    
    
    temp_p = p[root];
    strcpy(root_key, p[root].name);
    child = 2*root;
    
    while(child <= n){
        if((child<n)&&strcmp(p[child].name, p[child+1].name)>0){
            child++;
        }
        if(strcmp(root_key, p[child].name)<0){
            break;
        }
        else{
            p[child/2] = p[child];
            child *= 2;
        }
    }
    p[child/2] = temp_p;
}

/*
 It is sort the struct array in ascending order by using min heap sort.
 This function call the "adjusting" function.
 
 input : person struct array, list size
 output : none.
 */
void minHeapSort(person* p, int n){
    int i, j;
    person temp_p;
    
    for(i= n/2; i>0; i--){
        adjusting(p, i, n);
    }
    for(i=n-1; i>0; i--){
        SWAP(p[1], p[i+1], temp_p);
        adjusting(p, 1, i);
    }
}



/*
 This function insert the data into struct array.
 Read line is composed of name and age. So, this function split them and store into a struct array.
 
 And age will be added 2.
 
 input : data(name and age), index
 output : none.
 */
void insert(char* readLine, int index){
    int i,j;
    int count=0;
    int line_size;
    int per_age;
    
	char temp_name[20],temp_age[2];
    
	line_size = (int)strlen(readLine);
	
	for(i=0;i<line_size;i++)
	{
		if(readLine[i]=='|')
		{
			temp_name[i]='\0';
			break;
		}
		temp_name[i]=readLine[i];
		count++;
	}
	j=0;
	for(i=count+1;i<line_size;i++)
	{
		temp_age[j]=readLine[i];
		j++;
	}
	per_age=atoi(temp_age);
	p[index].age = per_age+2;
	strcpy(p[index].name,temp_name);
}