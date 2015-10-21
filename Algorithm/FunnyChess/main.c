
#include<stdio.h>
#include<stdlib.h>

void initialTable(int** table, int size);
void printTheTable(int** table, int size);
void countThaLoc(int** table, int size, int i, int j);
int checkSafe(int** table, int size, int i, int j);

int numOfbi=0; // total number of bishops..
int usedBi=0; // number of current used bishops..
int count=0; // total possible location..
int checkDange=0;

int main(void)
{
    int i, j;
    int size=0; // size of chess board..
    int** board;
    
    //input each value.. and make table...
    while(1)
    {
        printf("Enter the size of board : ");
        scanf("%d", &size);
        printf("Enter the number of bishop : ");
        scanf("%d",&numOfbi);
        if((1<=size && size<=10) && (0<=numOfbi && numOfbi<=size))
        {
            break;
        }
        if(size==0 && numOfbi==0)
        {
            printf("\n[program terminated]\n");
            exit(0);
        }
        printf("[ERROR] must : 1<=size<=10 and 0<=bishop<=size\n\n");
    }
    
    board = (int**)malloc(sizeof(int*)*size);
    for(i=0; i<size; i++)
    {
        board[i] = (int*)malloc(sizeof(int)*size);
    }

    //
    initialTable(board, size);
    
    
    
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            countThaLoc(board, size, i, j);
            board[i][j]=0;
        }
    }
    
    printf("final result is %d\n", count);
}

void countThaLoc(int** table, int size, int i, int j)
{
    
    
    
    int a, b;
    
    printf("[i:%d ,j:%d, usedBi:%d]\n",i,j, usedBi);
    //checkSafe를 통해 안전한지 확인하고 안전하지 않다면 그냥 리턴
    if(table[i][j]==1)
    {
        printf("SFSFSAFSAFSAFSADFSADF\n");
        checkDange=0;
        return;
    }
    if(checkSafe(table, size, i, j)==1)
    {
        printf("DANGER\n");
        return;
    }
    //
    
    table[i][j]=1;
    usedBi++;
    
    printTheTable(table, size);
    if(usedBi==numOfbi)
    {
        table[i][j]=0;
        count++;
        checkDange=1;
        printf("count : %d\n",count);
        usedBi--;
        return;
        
    }
    
    
    for(a=i; a<size; a++)
    {
        for(b=j; b<size; b++)
        {
            countThaLoc(table, size, a, b);
            if(checkDange==1)
            {
                table[a][b]=0;
                checkDange=1;
            }
        }
        j=0;
    }
    
    printf("'function finishied'\n");
    usedBi--;
    checkDange=1;
    
    
}

int checkSafe(int** table, int size, int i, int j)
{
    int result = 0;
    int p=i;
    int q=j;
    
    while(1)
    {
        if(p<0 || q<0)
        {
            break;
        }
        if(table[p][q]==1)
        {
            result=1;
            break;
        }
        p--;
        q--;
    }
    
    p=i;
    q=j;
    while(1)
    {
        if(p<0 || q>size-1)
        {
            break;
        }
        if(table[p][q]==1)
        {
            result=1;
            break;
        }
        p--;
        q++;
    }
    
    return result;
}
void initialTable(int** table, int size)
{
    int i, j;
    //table initialization..
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            table[i][j]=0;
        }
    }
    //
    
}
void printTheTable(int** table, int size)
{
    int i, j;
    
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

