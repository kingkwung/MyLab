#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void bigAdd(int* a, int* b); //big int 덧셈연산을 위한 함수
void bigSub(int* a, int* b); //big int 뺄셈연산을 위한 함수

int n; //배열크기지정을 위한 변수

int main(void)
{
    int i;
    
    
    int* a=0; //피연산자 1
    int* b=0; //피연산자 2
    
    int cip=0; //자릿수
    
    printf("Enter the the CIPHER : "); //자릿수 입력받는다
    scanf("%d",&cip);
    
    n=ceil((double)cip/(double)4); //받은 자리수에 기반하여 배열생성을 위한 크기값을 구해낸다
    printf("length of array : [%d]\n",n);
    
    a = (int*)malloc(sizeof(int)*n); // 동적할당으로 메모리할당하는 과정
    b = (int*)malloc(sizeof(int)*n);
    
    //test case
    a[0]=9999;
    a[1]=4444;
    a[2]=7777;
    a[3]=2222;
    a[4]=9999;
    
    b[0]=9111;
    b[1]=6666;
    b[2]=3333;
    b[3]=8888;
    b[4]=1111;
    
    
    printf("first : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    
    printf("second : ");
    for(i=0; i<n;i++)
        printf("%d ",b[i]);
    printf("\n\n");
    
    
    printf("add : ");
    bigAdd(a, b); // big int 덧셈연산
    
    printf("\n");
    
    printf("sub : ");
    bigSub(a, b); // big int 뺄셈연산
}

void bigAdd(int* a, int* b)
{
    int i;
    int cy=0;
    
    int* result = (int*)malloc(sizeof(int)*(n+1));
    // 두개의 피연산자를 더한 값은 생성된 자리수보다 한자리 더 클 수도 있으므로 n+1로 동적으로 메모리를 할당해준다
    for(i=0; i<n+1; i++) // 초기화
        result[i]=0;
    
    
    for(i=n-1; i>=0; i--){
        result[i+1] = a[i]+b[i] + cy;
        if(result[i+1]>=10000)
        {
            result[i+1] -= 10000;
            cy=1;
        }
        else
        {
            cy=0;
        }
    }
    
    
    if(a[0]+b[0]>=10000)
        result[0]=1;
    for(i=0; i<n+1; i++)
    {
        printf("%04d",result[i]);
    }
}

void bigSub(int* a, int* b)
{
    int i;
    int brr=0;
    
    int* result = (int*)malloc(sizeof(int)*(n+1));
    // 두개의 피연산자를 더한 값은 생성된 자리수보다 한자리 더 클 수도 있으므로 n+1로 동적으로 메모리를 할당해준다
    for(i=0; i<n+1; i++) // 초기화
        result[i]=0;
    
    
    for(i=n-1; i>=0; i--)
    {
        result[i+1] = a[i]-b[i]-brr;
        if(result[i+1]>=0)
        {
            brr=0;
        }
        else
        {
            result[i+1] += 10000;
            brr=1;
        }
    }
    
    for(i=0; i<n+1;i++)
    {
        //if(a[0]+b[0]<10000 && i==0)
            //continue;
        printf("%04d",result[i]);
    }
}