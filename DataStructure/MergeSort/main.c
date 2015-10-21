/*
 This program is recieve the students data from the file, and store it into struct array.
 
 This struct array will be sorted in name ascending order by merge sort.
    Main function call the function "mergeSort".
    mergeSort function call the function "mergePass".
    mergePass function call the function "merge"
 
 After the sort, this struct array printed in file "writeFile"
 
 2014/05/15, Made by 우영남.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person person;
struct person { // It is struct for student
    char name[20];
    int age;
};

void insert_data(person* p, char* data, int idx); // function declaration of 'insert_data'
void merge(person* initList, person* mergedList, int i, int m, int n); // function declaration of 'merge'
void mergePass(person* initList, person* mergedList, int n, int s);//function declaration of 'mergePass'
void mergeSort(person* a, int n);// function declaration of 'mergeSort'

int size=0; // It is the number of sudents.

int main(void)
{
    int i;
    char temp_line[30]; // temp variable for read a line
    person* p;
    
    FILE* readFile;
    FILE* writeFile;
    
    char readFile_name[20] = "input.txt";
    char writeFile_name[20] = "result.txt";
    
    readFile = fopen(readFile_name,"r");
    writeFile = fopen(writeFile_name, "w");
    
    if(readFile == NULL || writeFile == NULL){ // if file open fail, print the error message
        printf("FILE OPEN ERROR!\n");
        return 0;
    }
    
    //to get a number of people..
    while(fscanf(readFile, "%s",temp_line)!=EOF){
        size++;
    }
    fclose(readFile);
    
    readFile = fopen(readFile_name,"r");
    if(readFile == NULL){
        printf("FILE OPEN ERROR_2!\n");
        return 0;
    }
    
    //allocate the memory for 'person' struct array..
    p = (person*)malloc(sizeof(person)*size);
    
    //read a student data and insert it into 'p' array..
    i=0;
    while(fscanf(readFile, "%s", temp_line)!=EOF){
        insert_data(p, temp_line, i);
        i++;
    }
    
    //before the merge sort...
    printf("[BEFORE SORT]\n");
    for(i=0; i<size; i++){
        printf("%s|%d\n",p[i].name,p[i].age);
    }
    
    
    //call the "mergeSort" function
    mergeSort(p, size);
    
    
    //after the merge sort..
    printf("\n\n[AFTER SORT]\n");
    for(i=0; i<size; i++){
        printf("%s|%d\n",p[i].name,p[i].age);
        fprintf(writeFile, "%s|%d\n",p[i].name,p[i].age);
    }
    
    //file close
    printf("[COMPLETE]\n");
    fclose(readFile);
    fclose(writeFile);
}

/*
 It is sort and merge the initial list.
 
 And store it into 'mergedList'
 
 Input : initial list, list for store the merged data,
 Output : none.
 */

void merge(person* initList, person* mergedList, int i, int m, int n){
    int j,k,t;
	j= m+1;
	k=i;
	while ( i<=m && j <=n)
	{
		if(strcmp(initList[i].name,initList[j].name)<=0)
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}
	if(i>m)
		for (t=j ; t<=n;t++)
			mergedList[t] = initList[t];
	else
		for(t=i;t<=m;t++)
			mergedList[k+t-i] = initList[t];
}

/*
 MergePass function recieve the initial list, list for store the merged data, number of students, size of sub-list and merge the two list using 'merge' function.
 
 Input : initial list, list for store the merged data, number of students, size of sub-list
 Output : None.
 */
void mergePass(person* initList, person* mergedList, int n, int s){
    int i, j;
	for (i=0; i<n-2*s; i+=2*s)
		merge(initList, mergedList, i, i+s-1, i+2*s-1);
	if (i+s-1<n)
		merge(initList, mergedList, i, i+s-1, n-1);
	else
		for (j=i; j<=n;j++)
			mergedList[j] = initList[j];
}

/*
 mergeSort recieve the struct array, number of student and generate the extra struct array for merge sort.
 
 And call the function 'mergePass' and set the s*=2 in each step.
 
 Input : origin struct array, number of student
 Output : none.
 */
void mergeSort(person* a, int n){
    int s = 1;
	person* extra = (person*)malloc(sizeof(person)*size);
	
	while (s<n)
	{
		mergePass(a, extra, n, s);
		s*=2;
		mergePass(extra, a, n, s);
		s*=2;
	}
}


/*
 It is recieve the data and store it into struct array.
 
 First segment of a line(before '|') represent the name.
 Second segment of a line(after '|') represent the age.
 
 Input : struct array, line of data, position of struct array
 Output :none.
 */
void insert_data(person* p, char* data_line, int idx){
    char* token=NULL;
    
    token = strtok(data_line, "|");
    strcpy(p[idx].name, token);
    
    token = strtok(NULL, "\n");
    p[idx].age = atoi(token);
}


