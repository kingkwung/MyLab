#include <stdio.h>
#include <stdlib.h>

int getGCD(int a, int b);
void extendEuclid(int gcd, int a, int b);

int x;
int y;
int num=0;
int tempX;

int main(void)
{
    int a, b; //first input value and second input value...
    int gcd; //store the calculated gcd...
    int i, j, check;
    
    //Input the a and b...//
    while(1)
    {
        printf("Enter the a and b : ");
        scanf("%d %d", &a, &b);
        if(a<1000000001 || b<1000000001)
        {
            break;
        }
        printf("[ERROR] smaller than 1,000,000,001\n\n");
    }
    //
    
    //get gcd...//
    gcd = getGCD(a, b);
    //
    
    //calculating...//
    if(num%2==0)
    {
        extendEuclid(gcd, a, b);
    }
    else
    {
        i=0;
        while(1)
        {
            j=0;
            while(1)
            {
                x=j;
                y=i;
                if((a*x)+(b*y)==gcd)
                {
                    check=0;
                    break;
                }
                else if((a*x)+(b*y)<gcd)
                {
                    check=1;
                    break;
                }
                else
                {
                    j--;
                }
            }
            if(check==1)
            {
                i++;
            }
            else if(check==0)
            {
                break;
            }
        }
    }
    //
    printf("number : [%d]\n",num);
    printf("x:%d / y:%d / gcd:%d\n", x, y, gcd);
}

void extendEuclid(int gcd, int a, int b)
{
    if(b==0)
    {
        //when the b zero, set the x, y is 1, 0..//
        x=1;
        y=0;
        return;
        //
    }
    else
    {
        //calculating int x and int y using recursive...//
        extendEuclid(gcd, b, a%b);
        tempX=x;
        x=y;
        y=tempX - (a/b*y);
        return;
        //
    }
}

int getGCD(int a, int b)
{
    if(b==0)
    {
        num++;
        return a;
    }
    else
    {
        num++;
        return getGCD(b, a%b);
    }
}