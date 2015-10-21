#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inputTheStrings(char* firstLine, char* secondLine);//문자열을입력받는 함수입니다
void fillTheTable(int** table, int lenOfFirst, int lenOfSecond, int i, int j, char* firstLine, char* secondLine);//오리지널테이블을 채우는 함수입니다
void backTracing(int i, int j, int lenOfSecond); //백트래이싱으로 출력을 위한 배열을 채우는 함수입니다

int** copyTable;
int* printArr;
int count;
int main(void)
{
    int numOfTest=0;
    char firstLine[10000];
    char secondLine[100];
    int lenOfFirst;
    int lenOfSecond;
    int** table;
    
    int k;
    int i,j;
    
    
    //테스트케이스의 갯수를 입력합니다//
    printf("Enter the number of TestCase : ");
    scanf("%d",&numOfTest);
    //
    
    
    //정해진 횟수만큼 작업을 실행합니다//
    for(k=0; k<numOfTest; k++)
    {
        printf("\n");
        inputTheStrings(firstLine, secondLine);
        
        lenOfFirst = (int)strlen(firstLine);
        lenOfSecond = (int)strlen(secondLine);
        
        //출력을 위한 어레이 메모리동적할당//
        printArr = (int*)malloc(sizeof(int)*lenOfSecond);
        //
        
        //테이블을 만드는 과정입니다f//
        table = (int**)malloc(sizeof(int*)*(lenOfSecond+1));
        copyTable = (int**)malloc(sizeof(int*)*(lenOfSecond+1));
        for(i=0; i<(lenOfSecond+1); i++)
        {
            table[i] = (int*)malloc(sizeof(int)*(lenOfFirst+1));
            copyTable[i] = (int*)malloc(sizeof(int)*(lenOfFirst+1));
        }
        for(i=0; i<lenOfSecond+1;i++)
        {
            for(j=0; j<lenOfFirst+1; j++)
            {
                if(i==0 || j==0)
                {
                    table[i][j]=0;
                    copyTable[i][j]=0;
                }
            }
        }
        //
        
        //테이블을 완성하는 과정입니다//
        for(i=0; i<lenOfSecond; i++)
        {
            for(j=0; j<lenOfFirst; j++)
            {
                fillTheTable(table, lenOfFirst, lenOfSecond, i, j, firstLine, secondLine);
            }
        }
        //
        
        //테이블 출력부분//
        printf("\n<<TABLE>>\n");
        for(i=0; i<lenOfSecond+1; i++)
        {
            for(j=0; j<lenOfFirst+1; j++)
            {
                printf("%d ",table[i][j]);
            }
            printf("\n");
        }
        printf("\n<<copyTABLE>>\n");
        for(i=0; i<lenOfSecond+1; i++)
        {
            for(j=0; j<lenOfFirst+1; j++)
            {
                printf("%d ",copyTable[i][j]);
            }
            printf("\n");
        }
        //
        
        //백트레이싱을 이용해 어레이에 값을 저장하고 출력하는 합수입니다//
        backTracing(lenOfSecond, lenOfFirst, lenOfSecond);
        //
        
        
        //한싸이클구분짓는선//
        printf("\nNUMBUR OF LCS is <<%d>>\n", count);
        printf("---------------------------\n");
        //
        count=0;
    }
    //
    
}
void backTracing(int i, int j, int lenOfSecond)
{
    int k=lenOfSecond;
    
    if(i==1||j==1)
    {
        printArr[i-1] = j;
        
        if(copyTable[i][j]==1){
            printf("INDEXE\n");
            for(k=0; k<lenOfSecond; k++)
            {
                printf("[%d] ",printArr[k]);
            }
            printf("\n");
            count++;
        }
        if(j==1)
            return ;
    }
    if(copyTable[i][j]==1)
    {
        printArr[i-1] = j;
        backTracing(i-1, j-1, lenOfSecond);
        backTracing(i, j-1, lenOfSecond);
    }
    else
    {
        backTracing(i, j-1, lenOfSecond);
    }
}
void fillTheTable(int** table, int lenOfFirst, int lenOfSecond, int i, int j, char* firstLine, char* secondLine)
{
    int max=0;
    if(secondLine[i]==firstLine[j])
    {
        table[i+1][j+1] = table[i][j]+1;
        copyTable[i+1][j+1] = 1;
    }
    else
    {
        max = table[i+1][j];
        if(max<table[i][j+1])
        {
            max = table[i][j+1];
        }
        table[i+1][j+1]=max;
    }
}


void inputTheStrings(char* firstLine, char* secondLine)
{
    printf("Enter the FIRST input String[1~10000] : ");
    getchar();
    scanf("%[^\n]",firstLine);
    printf("Enter the SECOND input String[1~100]\n(MUST BE SUBSTRING OF FIRSTLINE) : ");
    getchar();
    scanf("%[^\n]",secondLine);
}
