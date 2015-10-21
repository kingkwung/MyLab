/*
 This program read the file and sort them in name ascending order using quick sort.
 And store it into another file.
 
 input : File "input.txt"
 ouput : File "result1.txt"
 
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
void quickSort(person* p, int letf, int right);
void insert(char* readLine, int index);

//main function
int main(void){
    FILE* readFile;
    FILE* writeFile;
    
    int i;
    int index;
    
    char readFile_name[20] = "input.txt";
    char writeFile_name[20] = "result1.txt";
    char readLine[30];
    
    readFile = fopen(readFile_name, "r");
    writeFile = fopen(writeFile_name, "w");
    
    //file open
    if(readFile == NULL || writeFile == NULL){
        printf("[ERROR]file open error");
        return 0;
    }
    
    index=0;
    while(fscanf(readFile, "%s", readLine)!=EOF){
        insert(readLine, index); // read the text file and send it into function "insert"
        index++;
    }
    
    quickSort(p, 0, size-1); // call the quick sort function
    
    printf("[RESULT]\n");
    for(i=0; i<size; i++){
        printf("%s|%d\n",p[i].name, p[i].age);
        
        fprintf(writeFile,"%s|%d\n",p[i].name, p[i].age);//write the sorted structs into a file
    }
    
    
    fclose(readFile);
	fclose(writeFile);
    printf("\n[PROGRAM TERMINATED]\n");
    
}

/*
 It is recieve the struct array and sort them in ascending order by using quick sort.
 It takes a reculsive form.
 
 input : person struct array, left(first of the list), right(last of the list).
 output : none.
 */
void quickSort(person* p, int left, int right){
    int i,j;
    
	char pivot[20];
    
	person temp_p;
    
	if(left < right)
	{
		i=left;
		j=right+1;
		strcpy(pivot,p[left].name);
        
		do{
			do i++; while(strcmp(p[i].name,pivot)<0);
			do j--; while(strcmp(p[j].name,pivot)>0);
			if(i<j)
				SWAP(p[i],p[j],temp_p);
		}while(i<j);
        
		SWAP(p[left],p[j],temp_p);
		quickSort(p,left,j-1);
		quickSort(p,j+1,right);
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