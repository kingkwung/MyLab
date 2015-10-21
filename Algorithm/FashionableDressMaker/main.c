#include <stdio.h>
#include <stdlib.h>

typedef struct job job;
struct job
{
    int index;
    int needDay;
    int panalty;
    double effi;
};

void sortTheJob(job* jobArr, int numOfJob);
int main(void)
{
    int numOfJob=0;
    int i;
    
    //User can input the 'numOfJob' about number of the job//
    printf("<NUMBER OF THE JOB must be 1 to 1000>\n");
    while(1)
    {
        printf("Enter the number of the job : ");
        scanf("%d",&numOfJob);
        if(1<=numOfJob && numOfJob<=1000)
        {
            break;
        }
        printf("[ERROR]number of the job must be 1 to 1000!\n\n");
    }
    //
    
    //'jobArr' get the memory size of the number of job through the dynamic memory allocation//
    job* jobArr = (job*)malloc(sizeof(job)*numOfJob);
    //
    
    printf("\n<NEED DAY must between 1 to 1000>\n");
    printf("<PANALTY COST must between 1 to 10000>\n");
    
    //User will input the job's day and job's panalty cost for number of the jab//
    for(i=0; i<numOfJob; i++)
    {
        jobArr[i].index = i+1;
        printf("\nEnter the 'NEED DAY' for %d's job : ",i+1);
        scanf("%d",&jobArr[i].needDay);
        if(jobArr[i].needDay<1 || jobArr[i].needDay>1000)
        {
            printf("[ERROR]<NEED DAY must between 1 to 1000!>\n");
            i--;
            continue;
        }
        printf("Enter the 'PANALTY COST' for %d's job : ", i+1);
        scanf("%d",&jobArr[i].panalty);
        if(jobArr[i].panalty<1 || jobArr[i].panalty>10000)
        {
            printf("[ERROR]<PANALTY COST must between 1 to 10000!>\n");
            i--;
            continue;
        }
        jobArr[i].effi = (double)jobArr[i].panalty/jobArr[i].needDay;
    }
    //
    
    //sortTheJob function sort the jabArr struct Array about each job's EFFIENCY//
    /*Kind of the sort is 'BUBBLE SORT' bubble sort is always check the nearest value of each step AND change the value or not.
     So I Use the BUBBLE SORT as one of the 'GREEDY ALGORITHM'
     */
    sortTheJob(jobArr, numOfJob);
    //
    
    //Finally, print the optimal procedure for minimal debt about complete the job//
    printf("\n\nRESULT : ");
    for(i=0; i<numOfJob; i++)
    {
        printf("[%d]",jobArr[i].index);
    }
    printf("\n");
    //
}

void sortTheJob(job* jobArr, int numOfJob)
{
    int i, j;
    double tempEffi;
    int tempIndex, tempNeedDay, tempPanalty;
    
    for(i=1; i<numOfJob; i++)
    {
        for(j=0; j<numOfJob-i; j++)
        {
            if(jobArr[j].effi<jobArr[j+1].effi || ((jobArr[j].effi==jobArr[j+1].effi)&&(jobArr[j].needDay>jobArr[j+1].needDay)))
            {
                tempIndex=jobArr[j].index;
                jobArr[j].index = jobArr[j+1].index;
                jobArr[j+1].index = tempIndex;
                
                tempNeedDay=jobArr[j].needDay;
                jobArr[j].needDay = jobArr[j+1].needDay;
                jobArr[j+1].needDay = tempNeedDay;
                
                tempPanalty=jobArr[j].panalty;
                jobArr[j].panalty = jobArr[j+1].panalty;
                jobArr[j+1].panalty = tempPanalty;
                
                tempEffi=jobArr[j].effi;
                jobArr[j].effi = jobArr[j+1].effi;
                jobArr[j+1].effi = tempEffi;
            }
        }
    }
}