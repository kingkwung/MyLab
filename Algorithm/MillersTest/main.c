/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int arr[1000];
int euclid(int a, int b) // find a gcd
{
    int r;
    r = a%b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int bit(int n)  //change a decimal number to binary numeral
{
    int count = 0;
    int n2;
    int i = 0;
    n2 = n;
    while(1)
    {
        if(n == 1){
            break;
        }
        n = n/2;
        count++;
    }
    for(i=count; i>=0; i--)
    {
        if(n2==1)
            arr[i] = n2;
        else{
            arr[i] = n2%2;
            n2 = n2/2;
        }
    }
    return count; //return the length of binary numeral
}
int mod(int a, int n, int exp)             //find a remainder using squaring algorithm
{                                 //n = input number, count = the length of binary number
    int i;                        //a = base
    int d = 1;
    int count = 0;
    count = bit(exp);
    for(i=0; i<=count; i++)
    {
        d = (d*d)%n;
        if(arr[i] == 1){
            d = (d*a)%n;
        }
    }
    return d;
}
void test(int n) //test the input number whether CarMichael number or not
{
    int k = 0, q = 0;   // k = integer, q = odd number
    int temp = n-1;
    int i, j;
    while(1)         // find a Carmichael numbers using Millar Rabin algorithm
    {
        if(temp%2 == 0){//인풋값이 홀수면
            temp = temp/2;
            k++;
        }
        else{ //인풋값이 짝수면..
            q = temp;
            break;
        }
    }
    if((n != 2 && n%2 == 0) || n==3){  //if n is even number or 3 it is not carmichael
        printf("%d is normal\n",n);
        return;
    }
    else
    {
        for(i=2;i<n-1;i++)  // this loop is using Fermat algorithm
        {
            if(euclid(n,i)==1)
            {
                if(mod(i,n,n) != i)
                {
                    printf("%d is normal\n",n);
                    return;
                }
            }
        }
        i = rand()%(n-3)+2;
        for(j=0;j<=k-1;j++) // this loop is using Miller-Rabin algorithm based on Fermat algorithm
        {
            if(mod(i,n,pow(2.0,j)*q) == n-1 || mod(i,n,q) == 1){
                printf("%d is normal\n",n);
                return;
            }
        }
    }
    printf("%d is CarMichael!!\n",n);
    return;
}
int main(void)
{
    int n = 0;
    //int i,j;
    //int checkF = 0;
    while(1){
        printf("Input : ");
        scanf("%d",&n);
        if((n<=2 || n > 65000) && n!=0){  //exception
            printf("Input  2 < n < 65,000 \n");
        }
        else if(n == 0)
            break;
        else
        {
            test(n);
        }
    }
}
*/


///*
//영남
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long getMOD(int a, int exp, int n); // get final MOD value..
void testing(long num);
int getGCD(int a, int b);

int main(void)
{
    long num=0;
    while(1)
    {
        printf("Enter the number : ");
        scanf("%ld", &num);
        
        if(num==0)
        {
            break;
        }
        if(num>=65000 || num<=2)
        {
            printf("[ERROR] number must >2 and <65000\n\n");
            continue;
        }
        if((num>2) && ((int)num%2==0))
        {
            printf("%.0ld is normal.(NON-PRIME)\n\n",num);
            continue;
        }
        
        testing(num);
    }
    
    printf("\n<PROGRAM TERMINATED>\n");
}

void testing(long num)
{
    long j;
    int a;
    long k=0;
    long q=0;
    long tempEXP=0;
    long cnum=num;
    long temp=0;
    
    //get k and q..//
    cnum --;
    while(1)
    {
        if(cnum%2==0)
        {
            k++;
            cnum = cnum/2;
        }
        else
        {
            q = cnum;
            break;
        }
    }
    //
    
    //first fermat test..
    for(a=2; a<=num-1; a++)
    {
        
        if(getMOD(a, (int)num, (int)num)!=a)
        {
            printf("%d is normal.(NON-PRIME)\n\n", (int)num);
            return;
        }
    }
    //
    
    //Miller Rabin Algorithm..//
    a = rand()%(num-3) + 2;
    
    if(getMOD(a, (int)q, (int)num)==1)
    {
        printf("%d is normal.(PRIME)\n\n", (int)num);
        return;
    }
    
    for(j=0; j<=k-1; j++)
    {
        tempEXP = (long)pow(2,j) * q;
        temp = getMOD(a, (int)tempEXP, (int)num);
        if(temp == num-1)
        {
            printf("%d is normal.(PRIME)\n\n",(int)num);
            return;
        }
    }
    
    printf("%d is Carmichael Number.\n\n", (int)num);
    //
    
}

long getMOD(int a, int exp, int n)
{
    int* bitArr; // bit ARRAY..
    int count=0; // length of binary
    int cexp = exp; // exponential number..
    
    int i;
    long c=0;
    long d=1;
    
    
    //make binary array...//
    while(1)
    {
        if(cexp==1)
        {break;}
        count++;
        
        cexp = cexp/2;
        
    }
    count++;
    
    bitArr = (int*)malloc(sizeof(int)*(count));
    cexp = exp;
    for(i=count-1; i>=0; i--)
    {
        bitArr[i] = cexp%2;
        cexp = cexp/2;
    }
    //
    
    
    //calcuating MOD...//
    for(i=0; i<count; i++)
    {
        
        c = 2*c;
        d = (d*d)%n;
        if(bitArr[i]==1)
        {
            c = c+1;
            d = (d*a)%n;
        }
        //printf("d : %ld\n", d);
    }
    //
    
    return d;
}

int getGCD(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return getGCD(b, a%b);
    }
}
//*/
