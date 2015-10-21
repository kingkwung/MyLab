#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct information information;
struct information
{
    int tid;
    char refund[5];
    char marital[10];
    int taxable;
    char cheat[5];
};

char standard_refund[5];
char standard_marital1[10];
char standard_marital2[10];
int standard_taxable;

void makeStandard(information* info, int n)
{
    int i;
    
    int min=100000;
    
    char temp_standard_refund[5];
    char temp_standard_marital1[10]="empty";
    char temp_standard_marital2[10]="empty";
    int temp_standard_taxable;
    
    for(i=0; i<n; i++){
        
        if(strcmp(info[i].cheat,"Yes")==0) // get standard refund..
        {
            strcpy(temp_standard_refund,info[i].refund);
        }
        
        if(strcmp(info[i].cheat,"Yes")==0) // get standard marital1 and 2..
        {
            if(strcmp(temp_standard_marital1,"empty")==0)
                strcpy(temp_standard_marital1,info[i].marital);
            else
                strcpy(temp_standard_marital2,info[i].marital);
        }
        
        if(strcmp(info[i].cheat,"Yes")==0) // get standard minimum taxable..
        {
            if(info[i].taxable<min)
            {
                temp_standard_taxable = info[i].taxable;
                min = info[i].taxable;
            }
        }
        
    }
    
    strcpy(standard_refund,temp_standard_refund);
    strcpy(standard_marital1,temp_standard_marital1);
    strcpy(standard_marital2,temp_standard_marital2);
    standard_taxable = temp_standard_taxable;
    
}

int main(void)
{
    int i, n;
    information* info;
    information standard_struct[2]; // two case of standard input..
    
    information test_struct;
    
    
    
    
    printf("Enter the number of information : ");
    scanf("%d",&n);
    
    info = (information*)malloc(sizeof(information)*n);
    
    
    for(i=0; i<n; i++) // insert the information..
    {
        printf("Enter the TID, REFUND, MARITAL, TAXABLE, CHEAT\n : ");
        scanf("%d %s %s %d %s",&info[i].tid,info[i].refund,info[i].marital,&info[i].taxable,info[i].cheat);
    }
    
    
    /*
    // test case..
    info[0].tid=1;
    info[1].tid=2;
    info[2].tid=3;
    info[3].tid=4;
    info[4].tid=5;
    info[5].tid=6;
    info[6].tid=7;
    info[7].tid=8;
    info[8].tid=9;
    info[9].tid=10;

    strcpy(info[0].refund,"Yes");
    strcpy(info[1].refund,"No");
    strcpy(info[2].refund,"No");
    strcpy(info[3].refund,"Yes");
    strcpy(info[4].refund,"No");
    strcpy(info[5].refund,"No");
    strcpy(info[6].refund,"Yes");
    strcpy(info[7].refund,"No");
    strcpy(info[8].refund,"No");
    strcpy(info[9].refund,"No");

    strcpy(info[0].marital,"Single");
    strcpy(info[1].marital,"Married");
    strcpy(info[2].marital,"Single");
    strcpy(info[3].marital,"Married");
    strcpy(info[4].marital,"Divorced");
    strcpy(info[5].marital,"Married");
    strcpy(info[6].marital,"Divorced");
    strcpy(info[7].marital,"Single");
    strcpy(info[8].marital,"Married");
    strcpy(info[9].marital,"Single");
    
    info[0].taxable=125;
    info[1].taxable=100;
    info[2].taxable=70;
    info[3].taxable=120;
    info[4].taxable=95;
    info[5].taxable=60;
    info[6].taxable=220;
    info[7].taxable=85;
    info[8].taxable=75;
    info[9].taxable=90;
    
    strcpy(info[0].cheat,"No");
    strcpy(info[1].cheat,"No");
    strcpy(info[2].cheat,"No");
    strcpy(info[3].cheat,"No");
    strcpy(info[4].cheat,"Yes");
    strcpy(info[5].cheat,"No");
    strcpy(info[6].cheat,"No");
    strcpy(info[7].cheat,"Yes");
    strcpy(info[8].cheat,"No");
    strcpy(info[9].cheat,"Yes");
    //
    */
    
    // print the information..
    printf("\n[DATA SET THAT YOU INPUT]\n");
    for(i=0; i<n; i++){
        printf("%d %s %s %d %s\n",info[i].tid,info[i].refund,info[i].marital,info[i].taxable,info[i].cheat);
    }
    
    makeStandard(info, n); // make standard function..
    
    //make standard struct..
    strcpy(standard_struct[0].refund,standard_refund);
    strcpy(standard_struct[0].marital,standard_marital1);
    standard_struct[0].taxable = standard_taxable;
    
    strcpy(standard_struct[1].refund,standard_refund);
    strcpy(standard_struct[1].marital,standard_marital2);
    standard_struct[1].taxable = standard_taxable;
    
    
    
    //input the new data..
    printf("\nEnter the 'NEW' TID, REFUND, MARITAL, TAXABLE, CHEAT\n : ");
    scanf("%d %s %s %d",&test_struct.tid, test_struct.refund, test_struct.marital, &test_struct.taxable);
    
    
    if(strcmp(test_struct.refund,standard_struct[0].refund)==0 && strcmp(test_struct.marital,standard_struct[0].marital)==0 && test_struct.taxable>=standard_struct[0].taxable)
    {
        printf("expected 'CHEAT'\n");
    }
    
    else if(strcmp(test_struct.refund,standard_struct[1].refund)==0 && strcmp(test_struct.marital,standard_struct[1].marital)==0 && test_struct.taxable>=standard_struct[1].taxable)
    {
        printf("expected 'CHEAT'\n");
    }
    else
    {
        printf("expected 'NOT CHEAT'\n");
    }
}