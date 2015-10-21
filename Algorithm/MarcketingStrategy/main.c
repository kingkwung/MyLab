
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point point;
struct point
{
    int x;
    int y;
};

double getDis(int x1, int y1, int x2, int y2);
void sortByX(point* p);
void sortByY(point* p);
double brute_force(point* p, int l, int r);
double closest_pair(point*p, int l, int r);
double getMin(double a, double b);

int numOfPoint=0;

int main(void)
{
    int i;
    int l,r;
    
    point* p = NULL;
    double result = 0;
    
    //input the value...//
    while(1)
    {
        printf("Enter the number of point : ");
        scanf("%d",&numOfPoint);
        if(numOfPoint<=40000 && numOfPoint>0)
        {
            break;
        }
        printf("[ERROR]number of Point ERROR!\n\n");
    }
    p = (point*)malloc(sizeof(point)*numOfPoint);
    for(i=0; i<numOfPoint; i++)
    {
        printf("Enter the location of point : ");
        scanf("%d %d",&p[i].x, &p[i].y);
    }
    //
    
    //sort by X..//
    sortByX(p);
    //
    
    l=0; // most left index
    r=numOfPoint-1; // most right index
    //printf("%lf\n",brute_force(p, l, r));
    //==========================================================//
    
    
    //get minimum length pair using closest fair algorithm..//
    l=0; // most left index
    r=numOfPoint-1; // most right index
    result = closest_pair(p,l,r);
    //
    
    //result += 0.05;
    printf("result : [%.2lf]\n",result);
}

//get closest pair function
double closest_pair(point* p, int l, int r)
{
    int i, j;
    int q;
    double dl, dr;
    double d;
    int count=0;
    point* S = (point*)malloc(sizeof(point)*numOfPoint);
    
    if((r-l)<3)
    {
        return brute_force(p, l, r);
    }
    q = ceil((double)((double)((l+r))/2));
    dl = closest_pair(p, l, q-1);
    dr = closest_pair(p, q, r);
    d = getMin(dl,dr);
    
    for(i=0; i<r; i++)
    {
        if((p[q].x-d)<= p[i].x && p[i].x<= (p[q].x+d))
        {
            S[count].x= p[i].x;
            S[count].y= p[i].y;
            count++;
        }
    }
    
    sortByY(p);
    
    for(j=0; j<count-2; j++)
    {
        if(getDis(S[j].x,S[j].y, S[j+1].x, S[j+1].y)<d)
        {
            d = getDis(S[j].x,S[j].y, S[j+1].x, S[j+1].y);
        }
    }
    
    
    
    
    return d;
}

//get minimum distance number of dot less than 3 or equal..
double brute_force(point* p, int l, int r)
{
    double min=100000;
    
    if((r-l)==2)
    {
        min = getDis(p[l].x,p[l].y,p[l+1].x,p[l+1].y);
        if(getDis(p[l+1].x,p[l+1].y,p[r].x,p[r].y)<min)
        {
            min = getDis(p[l+1].x,p[l+1].y,p[r].x,p[r].y);
        }
        if(getDis(p[l].x,p[l].y,p[r].x,p[r].y)<min)
        {
            min = getDis(p[l+1].x,p[l+1].y,p[r].x,p[r].y);
        }
        return min;
    }
    
    else
    {
        return getDis(p[l].x,p[l].y,p[r].x,p[r].y);
    }
}
void sortByY(point* p)
{
    int i, j;
    int tempX, tempY;
    
    for(i=0; i<numOfPoint-1; i++)
    {
        for(j=0; j<numOfPoint-1; j++)
        {
            if(p[j].y > p[j+1].y)
            {
                tempX = p[j].x;
                p[j].x = p[j+1].x;
                p[j+1].x = tempX;
                
                tempY = p[j].y;
                p[j].y = p[j+1].y;
                p[j+1].y = tempY;
            }
        }
    }
}


double getMin(double a, double b)
{
    if(a<b)
    {
        return a;
    }
    
    return b;
}

void sortByX(point* p)
{
    int i, j;
    int tempX, tempY;
    
    for(i=0; i<numOfPoint-1; i++)
    {
        for(j=0; j<numOfPoint-1; j++)
        {
            if(p[j].x > p[j+1].x)
            {
                tempX = p[j].x;
                p[j].x = p[j+1].x;
                p[j+1].x = tempX;
                
                tempY = p[j].y;
                p[j].y = p[j+1].y;
                p[j+1].y = tempY;
            }
        }
    }
}
double getDis(int x1, int y1, int x2, int y2)
{
    return sqrt((double)((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
}