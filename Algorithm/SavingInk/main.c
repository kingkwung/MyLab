#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Dot Dot;
struct Dot
{
    int x;
    int y;
    int check;
};

double getLength(int x1, int y1, int x2, int y2);

int main(void)
{
    int numOfDot;
    int i,j;
    int startOfDot;
    int tempIndex=0;
    double tempMin;
    double totalLen=0;
    
    Dot* dots;
    
    //점의 갯수를 입력받는 과정입니다//
    printf("Enter the number of Dots : ");
    scanf("%d",&numOfDot);
    //
    
    //메모리할당과정입니다//
    dots = (Dot*)malloc(sizeof(Dot)*numOfDot);
    //
    
    //초기화과정입니다//
    for(i=0; i<numOfDot; i++)
    {
        dots[i].x = 0;
        dots[i].y = 0;
        dots[i].check = 0;
    }
    //
    
    //입력받는과정입니다//
    for(i=0; i<numOfDot; i++)
    {
        printf("Enter the Location of X and Y : ");
        scanf("%d %d", &dots[i].x, &dots[i].y);
    }
    //
    
    
    startOfDot=0;
    for(i=0; i<numOfDot-1; i++)
    {
        tempIndex =0;
        tempMin = getLength(dots[startOfDot].x, dots[startOfDot].y, dots[startOfDot+1].x, dots[startOfDot+1].y);
        printf("[%lf]\n",tempMin);
        for(j=0; j<numOfDot-1; j++)
        {
            if(startOfDot==j || dots[j].check==1)
            {
                continue;
            }
            
            if(getLength(dots[startOfDot].x, dots[startOfDot].y, dots[j].x, dots[j].y) > getLength(dots[startOfDot].x, dots[startOfDot].y, dots[j+1].x, dots[j+1].y))
            {
                printf("INININININ!\n");
                tempIndex = j+1;
                tempMin = getLength(dots[startOfDot].x, dots[startOfDot].y, dots[j+1].x, dots[j+1].y);
                continue;
            }
            startOfDot++;
        }
        printf("[[%d]]\n",tempIndex);
        startOfDot = tempIndex;
        totalLen += tempMin;
    }
    
    printf("Shortest Path is %lf\n",totalLen);
}

double getLength(int x1, int y1, int x2, int y2)
{
    return sqrt((double)((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
}