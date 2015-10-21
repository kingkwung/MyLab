
#include <stdio.h>
#include <stdlib.h>

void makeTable(int** table, int numOfIntersection);
void findLocation(int** table, int numOfIntersection, int locationOfExCenter);

int main(void)
{
    int numOfExCenter=0; // number of the current exist health center...
    int numOfIntersection=0; // number of the intersections...
    int locationOfExCenter=0; // Location of the current exist health center...
    int inter1, inter2, weight; // inter 1 is first position of input line, inter1 means start vertics and inter2 is arrival vertics, and weigth means weight of between of them.
    int** table=NULL;
    int i, j;
    
    //input the current number of health center and number of intersection...//
    while(1)
    {
        printf("Enter the number of Health Center and Intersection : ");
        scanf("%d %d", &numOfExCenter, &numOfIntersection);
        if(numOfExCenter==1 && numOfIntersection<=500)
        {
            break;
        }
        if(numOfExCenter!=1) //handle the errer case...
        {
            printf("[ERROR]ASSUME that number of CENTER is 1\n\n");
        }
        else if(numOfIntersection>500)
        {
            printf("[ERROR] number of INTERSECTION must less than 500!\n\n");
        }
    }
    //
    
    //input the Location of current exist Center..//
    while(1)
    {
        printf("Enter the Location of current exist Health Center : ");
        scanf("%d", &locationOfExCenter);
        if(locationOfExCenter<=numOfIntersection && locationOfExCenter>=0)
        {
            break;
        }
        printf("[ERROR] Location error\n\n");
    }
    //
    
    //dynamic memory allocation about 'table'...//
    //and initializion..//
    table = (int**)malloc(sizeof(int*)*numOfIntersection);
    for(i=0; i<numOfIntersection; i++)
    {
        table[i] = (int*)malloc(sizeof(int)*numOfIntersection);
    }
    
    for(i=0; i<numOfIntersection; i++)//10000means never happen number, means infinity..
    {
        for(j=0; j<numOfIntersection; j++)
        {
            table[i][j]=10000;
        }
    }
    //
    
    //input the information about each vertics and edge...//
    for(i=0; i<numOfIntersection; i++)
    {
        printf("Enter the information about vertics and edges[ex)1 2 10] : ");
        scanf("%d %d %d", &inter1, &inter2, &weight);
        
        if(inter1>numOfIntersection || inter2>numOfIntersection)
        {
            printf("[ERRER] information error!\n\n");
            i--;
            continue;
        }
        
        table[inter1-1][inter2-1] = weight;
        table[inter2-1][inter1-1] = weight;
    }
    //
    
    //make the Shortest path about each vertics using Floyd-Warshall algorighm..//
    makeTable(table, numOfIntersection);
    //
    
    //show table...//
    printf("\n=====This is weigth table...=====\n");
    for(i=0; i<numOfIntersection; i++)
    {
        for(j=0; j<numOfIntersection; j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    printf("=================================\n");
    //
    
    //find the best Health center location and print it...//
    findLocation(table, numOfIntersection, locationOfExCenter);
    //
}

void findLocation(int** table, int numOfIntersection, int locationOfExCenter)
{
    int i;
    int maxLength=0;
    int finalLocation=0;

    for(i=0; i<numOfIntersection-1; i++)
    {
        if(maxLength<table[locationOfExCenter-1][i])
        {
            maxLength = table[locationOfExCenter-1][i];
            finalLocation=i+1;
        }
    }
    
    printf("\n<The best Location is [%d]>\n", finalLocation);
}

void makeTable(int** table, int numOfIntersection)
{
    int i, j, k;
    
    for(k=0; k<numOfIntersection; k++)
    {
		for(i=0; i<numOfIntersection; i++)
        {
			for(j=0; j<numOfIntersection; j++)
            {
				if(i==j)
                {
					table[i][j] = 0;
                }
				else
                {
					if(table[i][j] > table[i][k] + table[k][j])
						table[i][j] = table[i][k] + table[k][j];
                }
			}
        }
    }
}




//////////SUNG JIN//////////
/*
//
//  main.c
//  al_exm_12
//
//  Created by Sungjin Park on 13. 10. 10..
//  Copyright (c) 2013년 Sungjin Park. All rights reserved.
//
//  this program have not negative weight
//  because distance is absolute number
//  so, i hava UNKNOWN is negative (-10).
//  first compute the all distance between one location and another location with matrix
//  second, if i select the N`th intersection, compute the distant between N`th location and another location
//  final, select the total minimum cost.
//  distance only less than 1000000000


#include <stdio.h>
#include <stdlib.h>
int** inputCare(int);
int** healthCare(int **data,int intersectionNumber);
int calCulator(int **data,int intersectionNumber,int *locationCenter,int );

const int UNKNOWN=-10;
const int MAXDISTANCE=1000000000;




int main(int argc, const char * argv[])
{
    int healthCenterNumber;
    int **data;
    int intersectionNumber;
    int *locationCenter;
    
    
    
    printf("input the healthcenter number");
    scanf("%d", &healthCenterNumber);
    
    printf("input the intersectionNumber");
    scanf("%d", &intersectionNumber);
    
    locationCenter=(int*)malloc(sizeof(int)*healthCenterNumber);
    
    for(int i=0;i<healthCenterNumber;i++){
        printf("input the location Center");
        scanf("%d", &locationCenter[i]);
    }
    
    
    data=inputCare(intersectionNumber);
    
    for(int i=0;i<intersectionNumber;i++){
        data=healthCare(data,intersectionNumber);
        
    }//make a matrix.
    
    
    //compute the distance
    printf("\n\nresult is :%d intersection",calCulator(data, intersectionNumber, locationCenter,healthCenterNumber));
}


int calCulator(int **data,int intersectionNumber,int *locationCenter,int healthCenterNumber){
    //compute the distance
    int changeCost;
    int minCost;
    int idx=0;
    int min;
    
    
    
    minCost=MAXDISTANCE;
    printf("\n");
    for(int i=0;i<intersectionNumber;i++){
        changeCost=0;
        for(int j=0;j<intersectionNumber;j++){
            min=0;
            for(int k=0;k<healthCenterNumber;k++){
                if(data[locationCenter[min]-1][j]>data[j][locationCenter[k]-1]){
                    min=k;
                }
            }
            if(data[j][locationCenter[min]-1]>data[i][j]){
                changeCost+=data[i][j];
            }else{
                changeCost+=data[j][locationCenter[min]-1];
            }
            
        }
        if(minCost>changeCost){
            minCost=changeCost;
            idx=i;
        }
        printf("%d  `s cost: %d \n",i,changeCost);
    }
    return idx+1;
}

int** healthCare(int **data,int intersectionNumber){
    //make a matrix.
    
    int **duplicateData;
    
    duplicateData=(int**)malloc(sizeof(int*)*intersectionNumber);
    
    for(int i=0;i<intersectionNumber;i++){
        duplicateData[i]=(int*)malloc(sizeof(int)*intersectionNumber);
        for(int j=0;j<intersectionNumber;j++){
            duplicateData[i][j]=data[i][j];
        }
    }
    
    for(int k=0;k<intersectionNumber;k++){
        for(int i=0;i<intersectionNumber;i++){
            for(int j=0;j<intersectionNumber;j++){
                if((duplicateData[k][j]!=UNKNOWN&&duplicateData[j][i]!=UNKNOWN)){
                    if(duplicateData[k][i]==UNKNOWN)
                        data[k][i]=duplicateData[k][j]+duplicateData[j][i];
                    else if(data[k][i]>(data[k][j]+data[j][i]))
                        data[k][i]=duplicateData[k][j]+duplicateData[j][i];
                }
            }
        }
    }
    
    
    for(int i=0;i<intersectionNumber;i++){
        free(duplicateData[i]);
    }
    free(duplicateData);
    return data;
}

int** inputCare(int intersectionNumber){
    //input the number
    int **data;
    int inputRow;
    int inputCol;
    
    
    
    data=(int**)malloc(sizeof(int*)*intersectionNumber);
    for(int i=0;i<intersectionNumber;i++){
        data[i]=(int*)calloc(sizeof(int),intersectionNumber);
    }
    
    for(int i=0;i<intersectionNumber;i++){
        printf("%d`s input the row",i+1);
        scanf("%d",&inputRow);
        if(inputRow>intersectionNumber){
            printf("this intersection is not proper\n");
            i--;
            continue;
        }
        printf("%d`s input the col",i+1);
        scanf("%d",&inputCol);
        if(inputRow>intersectionNumber){
            printf("this intersection is not proper\n");
            i--;
            continue;
        }
        
        printf("%d`s input the cost",i+1);
        scanf("%d", &data[inputRow-1][inputCol-1]);
        data[inputCol-1][inputRow-1]=data[inputRow-1][inputCol-1];
    }
    
    for(int i=0;i<intersectionNumber;i++){
        for(int j=0;j<intersectionNumber;j++){
            
            if(i!=j&&data[i][j]==0){
                data[i][j]=UNKNOWN;
            }
        }
    }
    
    return data;
    
}
*/

/////////SANGMOON/////////
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ** makeTable(int numOfIS, int **table);   //Make a doubly nested table
int ** shortestPath(int numOfIS, int **table); //Change the table values using Floyed-Warshall algorithm
int findLocation(int numOfIS, int **table, int existLocation); // Find a location of new health center
void main()
{
	int i,j;
	int numOfIS = 0; // the number of intersections
	int numOfExist = 0; // the number of existing health centers. assume that the number of existing health centers is always 1
	int existLocation;  // the loacation of existing health centers.
	int newLocation;   // the location of new health center
	int **table = NULL; // first input table
	int road = 0, inter1 = 0, inter2 = 0; // length of road, intersections.
	printf("Input the number of existing healthe centers and intersections : ");
	scanf("%d %d",&numOfExist, &numOfIS);
	if(numOfIS > 500 || numOfExist > 100)  // exception
	{
		printf("You have to input the number of intersection less than 500 \n and the number of existing health centers less than 100");
		exit(0);
	}
	table = makeTable(numOfIS, table); // make a table
	
	for(i=1;i<=numOfIS;i++)   //initialize the values by max integer.
		for(j=1;j<=numOfIS;j++)
			table[i][j] = 100000;
    
	printf("Input the location of existing intersections : ");
	scanf("%d", &existLocation);
	fflush(stdin);
	
	for(i = 0; i<numOfIS; i++)
	{
		printf("Input three values : ");
		scanf("%d %d %d",&inter1, &inter2, &road);
		table[inter1][inter2] = road;  // put the input values into table;
		table[inter2][inter1] = road;
	}
    
	table = shortestPath(numOfIS, table); // Change the table values using Floyed-Warshall algorithm
	
     //for(i=1;i<=numOfIS;i++){   //this is changed table
     //printf("\n");
     //for(j=1;j<=numOfIS;j++)
     //printf("%d ",table[i][j]);
     //}
    for(i=0; i<numOfIS; i++)
    {
        for(j=0; j<numOfIS; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
	newLocation = findLocation(numOfIS, table, existLocation); // return a location of new health center
	printf("\nresult = %d\n", newLocation);
}
int findLocation(int numOfIS, int **table, int location)
{
	int i, j = 0;
	float avg;
	int temp = 0;
	int temp2;
	int count = 0;
	int *arr;
	int min = 1000000; // initialize a max integer
	for(i=1; i<=numOfIS; i++)
	{   // Caculate a average length of distance from all intersections to existing health club
		temp = temp + table[location][i];
	}
	avg = (float)temp/numOfIS;
    
	for(i=1; i<=numOfIS; i++)
	{   // calculate the number of intersectios that the distance to health center is longer than average
		if(table[location][i] > avg)
			count ++;
	}
	arr = (int*)malloc(sizeof(int)*count); // make a array using count value
    
	for(i=1; i<=numOfIS; i++) //so put the loaction of intersections what far from existing health center into array
	{
		if(table[location][i] > avg){
			arr[j] = i;
			j++;
		}
	}
	temp = 0;
	for(i=1; i<=numOfIS; i++)  //the values in the arr[] are location that far from existing health center
	{                          //so this loop find the intersection where the minimum distance from arr[] values
		temp2 = 0;
		for(j=0;j<count;j++)
			temp2 = temp2 + table[arr[j]][i];
		if(temp2 < min){
			min = temp2;
			temp = i;
		}
	}
	return temp;
}
int** makeTable(int num, int **table)
{
	int i;
	table = (int**)malloc(sizeof(int*) * num+1);
	for(i=0; i<num+1; i++)
		table[i] = (int*)malloc(sizeof(int) * num+1);
	return table;
}
int** shortestPath(int numOfIS, int **table)
{
	int i, j, k;
	for(k=1; k<=numOfIS; k++)
		for(i=1; i<=numOfIS; i++)
			for(j=1; j<=numOfIS; j++){
				if(i==j)
					table[i][j] = 0;
				else
					if(table[i][j] > table[i][k] + table[k][j])
						table[i][j] = table[i][k] + table[k][j];
			}
	return table;
}
*/




/*
#include <Stdio.h>
#include <Stdlib.h>
#include <math.h>

typedef struct dot dot;
struct dot
{
    int x;
    int y;
};


double getLength(int x1, int y1, int x2, int y2);

int main(void)
{
    int numOfDots=0;
    int i, j;
    dot* dots;
    double** table;

    printf("Enter the number of dots : ");
    scanf("%d", &numOfDots);
    
    //구조체생성...//
    dots = (dot*)malloc(sizeof(dot)*numOfDots);
    //
    
    
 
    //0 0 0 0 0 {노드1에서갈수있는 거리들}
    //0 0 0 0 0 {노드2에서갈수있는 거리들}
    //0 0 0 0 0 {노드3에서갈수있는 거리들}
    //0 0 0 0 0 {노드4에서갈수있는 거리들}
    //0 0 0 0 0 {노드5에서갈수있는 거리들}
 
    
    //테이블 생성...//
    table = (double**)malloc(sizeof(double*)*numOfDots);
    for(i=0; i<numOfDots; i++)
    {
        table[i] = (double*)malloc(sizeof(int)*numOfDots);
    }
    //
    
    
    //테이블초기화...//
    for(i=0; i<numOfDots; i++)
    {
        for(j=0; j<numOfDots; j++)
        {
            table[i][j]=0;
        }
    }
    //
    
    
    //점의 위치 입력받는 과정입니다..//
    for(i=0; i<numOfDots; i++)
    {
        printf("Enter the Location of %d's dot : ", i+1);
        scanf("%d %d", &dots[i].x, &dots[i].y);
    }
    //
    
    
    for(i=0; i<numOfDots; i++)
    {
        printf("[%d]dot's loc : %d, %d\n",i, dots[i].x, dots[i].y);
    }
    //테이블을 채우는 과정입니다..//
    for(i=0; i<numOfDots; i++)
    {
        for(j=0; j<numOfDots; j++)
        {
            printf("[%d][%d] ",i,j);
            table[i][j] = getLength(dots[i].x, dots[i].y, dots[j].x, dots[j].y);
        }
        printf("\n");
    }
    //
    
    //테이블 출력...//
    for(i=0; i<numOfDots; i++)
    {
        for(j=0; j<numOfDots; j++)
        {
            printf("[%f] ",table[i][j]);
        }
        printf("\n");
    }
    //
}

double getLength(int x1, int y1, int x2, int y2)
{
    return sqrt((double)((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
}
*/