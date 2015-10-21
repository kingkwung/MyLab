#include<Stdio.h>
#include<stdlib.h>


void inputTheMoney(int numOfStu); // Function of input the Spending money of each Students
void calculateMoney(int* CostArr, int numOfStu); // Function of CALCULATING OUTPUT MONEY 

int main(void)
{
    int numOfStu=0;
    
    printf("[[**This is Thanksgiving trip Program**]]\n\n");
    
    // main Function will have the information about number of students!
    
    while(1)
    {
        printf("Enter the number of Students[1~100]\n ('0'is PROGRAM TERMINATED) : ");
        scanf("%d",&numOfStu);
        
        if(numOfStu==0)
        {
            printf("[[Program Terminated]]");
            exit(0);
        }
        if(numOfStu<0 || numOfStu>100)
        {
            printf("[ERRER!] number of Students must between 1 to 100!!\n\n");
            continue;
        }
        
        inputTheMoney(numOfStu);
    }
}

void calculateMoney(int* CostArr, int numOfStu)
{
    int sum=0;
    int aver=0;
    double tempAver=0;
    int result=0;
    
    int i=0;
    
    for(i=0; i<numOfStu; i++)
    {
        sum+=CostArr[i];
    }
    tempAver = (double)sum/numOfStu;
    
    
    aver = ((int)(tempAver + 0.5));
    //printf("Average is %d\n",aver);
    
    for(i=0; i<numOfStu; i++)
    {
        if(CostArr[i]<aver)
        {
            result+=aver-CostArr[i];
        }
    }
    printf("\n[[Total EXCHANGED MONEY is %d(Won)!!]]\n\n",result);
}

void inputTheMoney(int numOfStu)
{
    int i=0;
    
    int* CostArr = (int*)malloc(sizeof(int)*numOfStu);
    
    for(i=0; i<numOfStu; i++)
    {
        int Cost=0;
        
        printf("Enter the %d's Student SPENED COST[0~100000] : ",i+1);
        scanf("%d",&Cost);
        if(Cost<0 || Cost>100000)
        {
            printf("[ERRER!] Cost must between 0 to 100000 Won!!!\n\n");
            i--;
            continue;
        }
        CostArr[i] = Cost;
    }
    
    calculateMoney(CostArr, numOfStu);
}