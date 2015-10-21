#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int getGCD(int a, int b); // get GCD function..

int encryptM(int num, int e, int n); // use encryption to get P(M)..
int decryptPM(int PM, int d, int n); // use decryption to get M..
int getMOD(int a, int exp, int n); // get final MOD value..
int testing(long num); // testing function to get PRIME NUMBER...

int main(void)
{
    int i;
    long p , q;
    int n=0;
    int n2=0; // use for (p-1)*(q-1)...
    int e=0;
    int d=0;
    int num=0;
    int PM=0; // P(M)
    int M=0; // Original Message
    int tempGCD=0;
    
    //input the number M...//
    printf("Enter the number : ");
    scanf("%d",&num);
    //
    
    //input the two large prime number..//
    while(1)
    {
        printf("Enter the two large prime number : ");
        scanf("%ld %ld", &p, &q);
        if(testing(p)==0 || testing(q)==0)
        {
            printf("[ERROR]You must enter the prime number!\n\n");
            continue;
        }
        break;
    }
    //
    
    //calculate the original n and n..//
    n=(int)(p*q);
    n2 = ((int)p-1)*((int)q-1);
    //
    
    //finding e..//
    for(i=3; i<n2; i++)
    {
        tempGCD = getGCD(n2, i);
        if(tempGCD==1)
        {
            e = i;
            break;
        }
    }
    //
    
    //finding d...//
    i=1;
    while(1)
    {
        d = n2*i + 1;
        if(d%e==0)
        {
            d = d/e;
            break;
        }
        i++;
    }
    //
    
    //ENC : M, e, n, P(M) // DEC : P(M), d, n
    
    PM = encryptM(num, e, n);
    
    printf("\nn = [%d] // e = [%d] // d = [%d]\n\n", n, e, d);
    printf("Encrypted Message P(M) = %d\n",PM);
    
    M = decryptPM(PM, d, n);
    
    printf("Decrypted Message M = %d\n\n",M);
    printf("<<PROGRAM TERMINATED>>\n");
}

int decryptPM(int PM, int d, int n) // get DECRYPTED number function...
{
    int M=0;
    
    M = getMOD(PM, d, n);
    
    return M;
}

int encryptM(int num, int e, int n) // get ENCRYPTED number function...
{
    int PM=0;
    
    PM = getMOD(num, e, n);
    
    return PM;
}

int getMOD(int a, int exp, int n)
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
    
    return (int)d;
}

int testing(long num)
{
    // if prime then 1, non prime is return 0..

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
            //printf("%d is normal.(NON-PRIME)\n\n", (int)num);
            return 0;
        }
    }
    //
    
    //Miller Rabin Algorithm..//
    a = rand()%(num-2) + 2;
    
    if(getMOD(a, (int)q, (int)num)==1)
    {
        //printf("%d is normal.(PRIME)\n\n", (int)num);
        return 1;
    }
    
    for(j=0; j<=k-1; j++)
    {
        tempEXP = (long)pow(2,j) * q;
        temp = getMOD(a, (int)tempEXP, (int)num);
        if(temp == num-1)
        {
            //printf("%d is normal.(PRIME)\n\n",(int)num);
            return 1;
        }
    }
    
    //printf("%d is Carmichael Number.\n\n", (int)num);
    return 0;
    //

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