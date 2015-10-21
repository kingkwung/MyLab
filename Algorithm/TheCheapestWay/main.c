#include <stdio.h>
#include <stdlib.h>

void calculator(int** table, int row, int col);
void backTracing(int** table, int** originTable, int row, int col);

int main(void)
{
    int row;
    int col;
    int i,j;
    int** table;
    int** originTable;
    
    //사용자로부터 테이블을 입력받는 과정입니다//
    while(1)
    {
        printf("Enter the size of TABLE(row:1~10 / col:1~100)\n[Ex) 5 6] : ");
        scanf("%d %d",&row, &col);
        if((row>=1&&row<=10)&&(col>=1&&col<=100))
        {
            break;
        }
        printf("[ERROR!]Enter the Correct Number!\n\n");
    }
    //
    
    //입력받은사이즈로 테이블을 만드는 과정입니다//
    originTable = (int**)malloc(sizeof(int*)*row);
    for(i=0; i<row; i++)
    {
        originTable[i] = (int*)malloc(sizeof(int)*col);
    }
    
    table = (int**)malloc(sizeof(int*)*row);
    for(i=0; i<row; i++)
    {
        table[i] = (int*)malloc(sizeof(int)*col);
    }
    //
    
    /*
    //테이블을 채우는 과정입니다//
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("\nEnter the input number : ");
            scanf("%d",&originTable[i][j]);
        }
    }
    //
    */
    
    originTable[0][0]=3;
    originTable[0][1]=4;
    originTable[0][2]=1;
    originTable[0][3]=2;
    originTable[0][4]=8;
    originTable[0][5]=6;
    
    originTable[1][0]=6;
    originTable[1][1]=1;
    originTable[1][2]=8;
    originTable[1][3]=2;
    originTable[1][4]=7;
    originTable[1][5]=4;
    
    originTable[2][0]=5;
    originTable[2][1]=9;
    originTable[2][2]=3;
    originTable[2][3]=9;
    originTable[2][4]=9;
    originTable[2][5]=5;
    
    originTable[3][0]=8;
    originTable[3][1]=4;
    originTable[3][2]=1;
    originTable[3][3]=3;
    originTable[3][4]=2;
    originTable[3][5]=6;
    
    originTable[4][0]=3;
    originTable[4][1]=7;
    originTable[4][2]=2;
    originTable[4][3]=1;
    originTable[4][4]=2;
    originTable[4][5]=3;
    
    
    //originTable값을 table로 복사하는 과정입니다//
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            table[i][j] = originTable[i][j];
        }
    }
    //
    
    //테이블 출력부분1//
    printf("\n<This is ORIGIN TABLE>\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", originTable[i][j]);
        }
        printf("\n");
    }
    //
    
    //shortest path를 찾는 함수 실행//
    calculator(table, row, col);
    //
    
    //테이블 출력부분2//
    printf("\n<This is COST TABLE>\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    //
    
    printf("\n");
    backTracing(table, originTable, row, col);
}

void backTracing(int** table, int** originTable, int row, int col)
{
    int i, j;
    int min;
    int copyMin;
    int minRow=0;
    int* rowArr;
    
    rowArr = (int*)malloc(sizeof(int)*col);
    
    //시작할 최소값과 그 인덱스를 찾는 과정입니다//
    min = table[0][col-1];
    for(i=0; i<row; i++)
    {
        if(min>table[i][col-1])
        {
            min = table[i][col-1];
            minRow = i;
        }
    }
    copyMin = min;
    //
    
    //backTracing을 하면서 cheapest way 인덱스를 찾아가는 과정입니다//
    for(j=(col-1); j>0; j--)
    {
        if(j==col-1)
        {
            rowArr[j]=minRow;
        }
        
        
        min = table[minRow][j-1];
        
        //
        if(minRow==0)
        {
            if(min>table[(row-1)-1][j-1])
            {
                min = table[(row-1)-1][j-1];
                minRow = (row-1)-1;
            }
            if(min>table[minRow+1][j-1])
            {
                min = table[minRow+1][j-1];
                minRow = minRow+1;
            }
        }
        //
        
        //
        if(minRow == row-1)
        {
            if(min>table[minRow-1][j-1])
            {
                min = table[minRow-1][j-1];
                minRow = minRow-1;
            }
            if(min>table[0][j-1])
            {
                min = table[0][j-1];
                minRow = 0;
            }
        }
        //
        
        //
        else
        {
            if(min>table[minRow-1][j-1])
            {
                min = table[minRow-1][j-1];
                minRow = minRow-1;
            }
            if(min>table[minRow+1][j-1])
            {
                min = table[minRow+1][j-1];
                minRow = minRow+1;
            }
        }
        //
        //
        rowArr[j-1]=minRow;
    }
    
    printf("\n<CHEAPEST WAY>\n");
    for(i=0; i<col; i++)
    {
        printf("[%d] ", originTable[rowArr[i]][i]);
    }
    printf("\n\n<CHEAPEST COST>\n");
    printf("%d\n",copyMin);
}

void calculator(int** table, int row, int col)
{
    int i, j;
    int min=0;
    for(j=1; j<col; j++)
    {
        for(i=0; i<row; i++)
        {
            min = table[i][j]+table[i][j-1];
            
            if(i==0)
            {
                if(min>table[i][j]+table[row-1][j-1])
                {
                    min = table[i][j]+table[row-1][j-1];
                }
                if(min>table[i][j]+table[i+1][j-1])
                {
                    min = table[i][j]+table[i+1][j-1];
                }
                table[i][j] = min;
            }
            else if(i==(row-1))
            {
                if(min>table[i][j]+table[i-1][j-1])
                {
                    min = table[i][j]+table[i-1][j-1];
                }
                if(min>table[i][j]+table[0][j-1])
                {
                    min = table[i][j]+table[0][j-1];
                }
                table[i][j] = min;
            }
            else
            {
                if(min>table[i][j]+table[i-1][j-1])
                {
                    min = table[i][j]+table[i-1][j-1];
                }
                if(min>table[i][j]+table[i+1][j-1])
                {
                    min = table[i][j]+table[i+1][j-1];
                }
                table[i][j] = min;
            }
        }
    }
}