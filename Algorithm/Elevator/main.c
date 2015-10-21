#include <stdio.h>
#include <stdlib.h>

int* getOff;
int TOTAL_FLOORS;
int numOfRiders;
int MAX_STOP;

int** table;	//cost table...//
int** OriginTable;

int calculate();
int LenthOfWalk(int previous, int current);
void FindTheWay(int LastLoc, int ToWalk);

int main(void)
{
    int i, j;
    int StopLoc;
    
    //input the each information...//
    printf("Enter the number of RIDERS : ");
    scanf("%d",&numOfRiders);
    printf("Enter the number of MAX STOP : ");
    scanf("%d",&MAX_STOP);
    printf("Enter the Total Floor of  building : ");
    scanf("%d", &TOTAL_FLOORS);
    printf("\n");
    //
    
    //create the table and dynamic memory allocation...//
    table = (int**)malloc(sizeof(int*)*TOTAL_FLOORS+1);
    OriginTable = (int**)malloc(sizeof(int*)*TOTAL_FLOORS+1);
    for(i=0; i<TOTAL_FLOORS+1; i++)
    {
        table[i] = (int*)malloc(sizeof(int)*numOfRiders);
        OriginTable[i] = (int*)malloc(sizeof(int)*numOfRiders);
    }
    
    getOff = (int*)malloc(sizeof(int)*numOfRiders);
    //
    
    //input the each destination of each RIDER...//
    for (i=1; i<=numOfRiders; i++)
    {
        printf("Enter the destination of [%d's] person : ", i);
        scanf("%d",&getOff[i]);
    }
    printf("\n");
    //
    
    
    StopLoc = calculate();
    
    //print the Cost and Origin Cost table...//
    printf("\t<<This is cost table>>\n");
    for (j=0; j<=MAX_STOP; j++) {
        for (i=0; i<=TOTAL_FLOORS; i++)
            printf("%3d",table[i][j]);
        printf("\n");
    }
    printf("//////////////////////////////////////\n\n");
    printf("\t<<This is Origin table>>\n");
    for (j=0; j<=MAX_STOP; j++) {
        for (i=0; i<=TOTAL_FLOORS; i++)
            printf("%3d",OriginTable[i][j]);
        printf("\n");
    }
    printf("//////////////////////////////////////\n\n");
    //
    
    printf("cost : %d\n",table[StopLoc][MAX_STOP]);
    
    FindTheWay(StopLoc, MAX_STOP);
    
}


int calculate()
{
    int i,j,k;
    int cost;
    int StopLoc;	//Last location of elevator's stop...//
    
    for (i=0; i<=TOTAL_FLOORS; i++)
    {
        table[i][0] = LenthOfWalk(0,100000); //Assume that 100000 is MAX INT...//
        OriginTable[i][0] = -1;
    }
    
    for (j=1; j<=MAX_STOP; j++)
        for (i=0; i<=TOTAL_FLOORS; i++)
        {
            table[i][j] = 100000;
            for (k=0; k<=i; k++)
            {
                cost = table[k][j-1] - LenthOfWalk(k,100000) + LenthOfWalk(k,i) + LenthOfWalk(i,100000);
                if (cost < table[i][j])
                {
                    table[i][j] = cost;
                    OriginTable[i][j] = k;
                }
            }
        }
    
    StopLoc = 0;
    
    for (i=1; i<=TOTAL_FLOORS; i++)
    {
        if (table[i][MAX_STOP] < table[StopLoc][MAX_STOP])
        {
            StopLoc = i;
        }
    }
    
    return(StopLoc);
}




int LenthOfWalk(int previous, int current)
{
    int LenOfWalk=0;//Length of Walked floors...//
    int i;
    
    for (i=1; i<=numOfRiders; i++)
        if ((getOff[i] > previous) && (getOff[i] <= current))
        {
            if(getOff[i]-previous < current-getOff[i])
            {
                LenOfWalk += getOff[i]-previous;
            }
            else
            {
                LenOfWalk += current-getOff[i];
            }
        }
    
    return LenOfWalk;
}


void FindTheWay(int LastLoc, int ToWalk)
{
    if (ToWalk > 1)
    {
        FindTheWay( OriginTable[LastLoc][ToWalk], ToWalk-1);
    }
    
    printf("[%d]\n",LastLoc);
}


