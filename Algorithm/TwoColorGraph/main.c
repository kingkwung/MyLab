#include<stdio.h>
#include<stdlib.h>

int valid(int i, int c);
int kColoring(int i, int c, int n);

int* color;
int** edge;
int d=0;
int main(void)
{
    int i, j;
    int n;
    int start, end;
    
    //input sequence...
    while(1)
    {
        printf("Enter the number of EDGE : ");
        scanf("%d",&n);
        
        if(0<n && n<=30)
        {
            break;
        }
        if(n==0)
        {
            printf("[program terminated]\n");
            exit(0);
        }
        printf("[ERROR] n should 0<n<=30\n\n");
    }
    //
    
    //memory allocation..
    edge = (int**)malloc(sizeof(int*)*(n+1));
    for(i=0; i<n+1; i++)
    {
        edge[i] = (int*)malloc(sizeof(int)*(n+1));
    }
    color = (int*)malloc(sizeof(int*)*(n+1));
    //
    
    
    //initialization..
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<n+1; j++)
        {
            edge[i][j]=0;
        }
    }
    for(i=0; i<n+1; i++)
    {
        color[i]=-1;
    }
    //
    
    //draw the connection map..
    for(i=0; i<n; i++)
    {
        printf("Enter the Start node , End node : ");
        scanf("%d %d",&start, &end);
        edge[start][end]=1;
        edge[end][start]=1;
    }
    //
    
    
    //start the depth-first
    kColoring(0, 0, n);
    //
    
    for(i=0; i<n+1; i++){
        printf("%d ",color[i]);
    }
    for(i=0; i<n+1; i++)
    {
        if(1<color[i])
        {
            printf("\nnot two-color graph\n");
            printf("[program terminated]\n");
            exit(0);
        }
    }
    printf("\ntwo-color graph\n");
    printf("[program terminated]\n");
}

int kColoring(int i, int c, int n) // get number of color
{
    int result;
    
    if(valid(i,c))
    {
        color[i]=c;
    
        if(i==n)
        {
            return 1;
        }
        else
        {
            result = 0;
            d=0;
            while(result == 0 && d<=n+1)
            {
                result = kColoring(i+1, d, n);
                d++;
            }
        }
        return result;
    }
    else
    {
        return 0;
    }
}

int valid(int i, int c) // check the i and c valid or not
{
    int j=0;

    for(j=0; j<=i-1; j++)
    {
        if(edge[i][j]==1 && color[j]==c)
        {
            return 0;
        }
    }
    
    return 1;
}