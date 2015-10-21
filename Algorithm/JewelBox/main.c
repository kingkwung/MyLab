#include<stdio.h>
#include<stdlib.h>

typedef struct boxInfo boxInfo;
struct boxInfo
{
    int Cost;
    int Capacity;
};
void insertInfo(boxInfo* box);
void compare(boxInfo* box, int numOfJewels);
void calculator(int numOfJewels, boxInfo* box, int check); // GREEDY ALGORITHMS구현부분
int main(void)
{
    int numOfJewels;
    boxInfo* box;
    
    while(1)
    {
        //보석의 갯수와 박스종류의 갯수를 입력받는 과정입니다
        while(1)
        {
            printf("How many Jewles do you have?(0<Jewel<1000) : ");
            scanf("%d",&numOfJewels);
            if(numOfJewels>0 && numOfJewels<1000)
            {
                break;
            }
            if(numOfJewels==0)
            {
                printf("[[PROGRAM TERMINATED]]\n");
                exit(1);
            }
            printf("[ERROR!] 0<Number of jewels<1000 !!\n\n");
        }
        //
        
        //2개의 박스 구조체메모리와 정수어레이를 할당해주는 과정입니다//
        box = (boxInfo*)malloc(sizeof(boxInfo)*2);
        //
        
        //구매할 박스값을 입력받는 함수입니다//
        insertInfo(box);
        //
        
        //입력받은 박스를 비교하여 연산값으로 보내는 함수입니다//
        compare(box, numOfJewels);
        //
        
        
        //[GREEDY ALGORITHMS]는 compare함수 안에 구현되어있습니다!!//
        
    }
}

void calculator(int numOfJewels, boxInfo* box, int check)
{
    int numOfFirstBox=0;
    int numOfSecondBox=0;
    
    if(check==1)
    {
        while(numOfJewels>=box[0].Capacity && numOfJewels>box[1].Capacity)
        {
            numOfFirstBox++;
            numOfJewels-=box[0].Capacity;
        }
        
        while(numOfJewels>=box[1].Capacity)
        {
            numOfSecondBox++;
            numOfJewels-=box[1].Capacity;
        }
        
    }
    else if (check==2)
    {
        while(numOfJewels>=box[1].Capacity && numOfJewels>box[0].Capacity)
        {
            numOfSecondBox++;
            numOfJewels-=box[1].Capacity;
        }
        
        while(numOfJewels>=box[0].Capacity)
        {
            numOfFirstBox++;
            numOfJewels-=box[0].Capacity;
        }
    }
    if(numOfJewels!=0)
    {
        printf("\n[FAILED]\n============================\n");
        return;
    }
    
    printf("\n'FIRST BOX' / 'SECOND BOX'\n");
    printf("    [%d]    /    [%d]   \n",numOfFirstBox, numOfSecondBox);
    printf("============================\n");
}

void compare(boxInfo* box, int numOfJewels)
{
    double val0, val1;
    int check=0;
    
    val0 = (double)box[0].Capacity/box[0].Cost;
    val1 = (double)box[1].Capacity/box[1].Cost;
    
    if(val0>=val1)
    {
        check=1;
    }
    else if(val0<val1)
    {
        check=2;
    }
    
    //[GREEDY ALGORITHMS구현부]//
    //최소금액이 되는 보석상자의 갯수를 계산하고 출력하는 함수입니다//
    //
    calculator(numOfJewels, box, check);
    
    
}

void insertInfo(boxInfo* box)
{
    int i;
    
    //박스구조체의 내용을 채우는 과정입니다//
    for(i=0; i<2; i++)
    {
        printf("Enter the %d box's Cost and Capacity(1~1000)\n[Ex)1 3] :  ",i+1);
        scanf("%d %d",&box[i].Cost, &box[i].Capacity);
        if((box[i].Cost<1 || box[i].Cost>1000) || (box[i].Capacity<1 || box[i].Capacity>1000))
        {
            printf("[ERROR!] Cost and Capacity must between 1 to 1000!!\n\n");
            i--;
            continue;
        }
    }
    //
}


