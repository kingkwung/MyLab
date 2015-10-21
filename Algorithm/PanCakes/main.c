#include<stdio.h>
#include<stdlib.h>

void printPanCakes(int* panCakes); //팬캐익의 현재상태를 출력해주는 함수
void inputPanCakes(void); // 팬케익을 입력시키는 함수
int checkPanCakes(int* panCakes); // 팬케익이 크기별로 정렬 되어있는지 확인하는 함수
// 완료되면 리턴1, 아직 안되었으면 리턴 0
void sortPanCakes(int* panCakes); // 사용자로부터 임의로 입력된 팬케익들을 크기순으로 정렬하는함수
//(나중에 플립할때 하나씩 꺼내쓰기위함)
void Flip(int max, int bottomIndex);

int* panCakes; // 팬케익을 담는 어레이들
int* comparePanCakes;
int sizePanCakes=0;
int flipPoint=50;//팬케익의 갯수는 어차피 30을 넘지 못하므로 50으로 초기화!

int main(void)
{
    int i;
    while(1) // 팬케익의 사이즈를 입력받는 부분
    {
        printf("Enter the size of panCakes(less than 30) : ");
        scanf("%d",&sizePanCakes);
        if(sizePanCakes>=1 && sizePanCakes<=30)
        {
            break;
        }
        else
        {
            printf("[ERRER]size of PanCakes should be in 1 to 30\n\n");
        }
    }
    
    panCakes = (int*)malloc(sizeof(int)*sizePanCakes); // sizePanCakes만큼 동적메모리 할당
    comparePanCakes = (int*)malloc(sizeof(int)*sizePanCakes);
    inputPanCakes();
    printf("\n--------------------------------\n");
    printf("<<<<<Let's begin FLIPPING!!>>>>>\n");
    printf("--------------------------------");
    
    for(i=0; i<sizePanCakes; i++)
    {
        
        Flip(comparePanCakes[i],sizePanCakes-1-i);
        
        if(checkPanCakes(panCakes)==1)//팬케익정렬이 완성되었나 검사
        {
            printPanCakes(panCakes);
            printf("--------------------------------\n");
            printf("Congratulation!\nPROGRAM TERMINATED\n");
            printf("--------------------------------\n");
            exit(0);
        }
    }
    
    //printPanCakes(panCakes);
}
void Flip(int max, int bottomIndex)
{
    int i, j, temp;
    int maxIndex=0; // max값의 인덱스, 그리고 fliping 시 swap 횟수로도 사용된다
    int skipControl=0;
    
    for(i=0; i<sizePanCakes;i++)
    {
        if(panCakes[i]==max)
        {
            break;
        }
        maxIndex++;
    }
    //최대지름팬케잌이 가장 밑에 깔려 있는 경우에는 flip을 skip한다
    if(maxIndex == bottomIndex)
    {
        return;
    }
    if(maxIndex == 0)
    {
        skipControl=1;
    }
    ////
    if(skipControl==0)
    {
        
        
        flipPoint=maxIndex;
        printPanCakes(panCakes);
        //printf("MaxIndex : %d\nbottmIndex : %d\n",maxIndex,bottomIndex);
        //printf("flip : [%d]\n",maxIndex+1);
        for(i=0; i<maxIndex;i++)
        {
            for(j=0; j<maxIndex-i;j++)
            {
                temp = panCakes[j+1];
                panCakes[j+1] = panCakes[j];
                panCakes[j]=temp;
            }
        }
    }
    
    
    
    flipPoint=bottomIndex;
    printPanCakes(panCakes);
    //printf("MaxIndex : %d\nbottmIndex : %d\n",maxIndex,bottomIndex);
    //printf("flip : [%d]\n",bottomIndex+1);
    for(i=0; i<bottomIndex;i++)
    {
        for(j=0; j<bottomIndex-i; j++)
        {
            temp = panCakes[j+1];
            panCakes[j+1] = panCakes[j];
            panCakes[j]=temp;
        }
    }
    
}
void sortPanCakes(int* comparePanCakes)
{
    int i;
    int j;
    int temp;
    
    for(i=0; i<sizePanCakes;i++)
    {
        comparePanCakes[i] = panCakes[i];
    }
    //1. comparePanCakes에 복사완료
    for(i=0; i<sizePanCakes-1; i++)
    {
        for(j=0; j<sizePanCakes-1-i; j++)
        {
            if(comparePanCakes[j]<comparePanCakes[j+1])
            {
                temp = comparePanCakes[j];
                comparePanCakes[j] = comparePanCakes[j+1];
                comparePanCakes[j+1] = temp;
            }
        }
    }
    //내림차순으로 정렬완료
}
int checkPanCakes(int* panCakes)
{
    int i;
    for(i=1; i<sizePanCakes; i++)
    {
        if(panCakes[i-1]>panCakes[i])
        {
            return 0; // 팬케익이 크기별로 아직 안되어있으면 리턴 0
        }
    }
    flipPoint = 50;
    return 1; // 팬케익이 크기별로 다 놓였으면 리턴 1
}

void inputPanCakes(void)
{
    int i;
    for(i=0; i<sizePanCakes; i++)
    {
        printf("Enter the diameter of [%d's]panCakes(1~10) : ",i+1);
        scanf("%d",&panCakes[i]);
        if(panCakes[i]<1 || panCakes[i]>10)
        {
            printf("[ERRER]diamter should be in 1 to 10!!!\n\n");
            i--;
            continue;
        }
    }
    sortPanCakes(comparePanCakes);//원본의팬케익과 비교를 위해 배열을 만드는 것을 하는 함수
}

void printPanCakes(int* panCakes)
{
    int i;
    printf("\n*Your current PanCakes*\n");
    for(i=0; i<sizePanCakes; i++)
    {
        printf("%d",panCakes[i]);
        if((flipPoint>=0 && flipPoint<sizePanCakes)&&flipPoint==i)
        {
            printf("[FLIP POINT!]\n");
            continue;
        }
        printf("\n");
    }
    
    
    
}

