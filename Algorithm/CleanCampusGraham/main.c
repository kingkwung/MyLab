#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct point point;
struct point
{
    double x;
    double y;
    int AngWithStartPoint;
};

int ccw(point p1, point p2, point p3); // if ccw then return 1, else retur -1
int getAng(double x1, double y1, double x2, double y2); // get Angle function...
void sortByAng(point* p, int numOfPoint); // sort by angle function...
double grahamScan(point* p, int numOfPoint, int* stack); // return total distance...
double getDis(double x1, double y1, double x2, double y2); // getDistance function...


int main(void)
{
    int i, j;
    int numOfTest=0;
    int numOfPoint=0;
    int* stack = NULL;
    point* p = NULL;
    double dis=0;
    
    //input the each informations... and memory allocation....
    printf("Enter the number of the testCase : ");
    scanf("%d", &numOfTest);
    
    for(j=0; j<numOfTest; j++)
    {
    while(1)
    {
        printf("Enter the number of point : ");
        scanf("%d", &numOfPoint);
        if(numOfPoint<=100)
        {
            break;
        }
        printf("[ERROR] number of point <=100 \n\n");
    }
    numOfPoint++;
    
    stack = (int*)malloc(sizeof(int)*numOfPoint);
    stack[0]=0;
    p = (point*)malloc(sizeof(point)*numOfPoint);
    p[0].x =0;
    p[0].y =0;
    p[0].AngWithStartPoint =0;
    
    for(i=0; i<numOfPoint; i++)
    {
        p[i].AngWithStartPoint =0; // initialization angle with start point
    }
    
    for(i=1; i<numOfPoint; i++)
    {
        printf("Enter the [%d]loc : ", i);
        scanf("%lf %lf",&p[i].x, &p[i].y);
        p[i].AngWithStartPoint = getAng(p[0].x, p[0].y, p[i].x, p[i].y);
        //set the each angle with the start point(0,0)...
        stack[i]=100;
    }
    //
    
    //sort by angle..
    sortByAng(p, numOfPoint);
    //
    
    dis = grahamScan(p,numOfPoint, stack);
    dis +=2;
        
    //dis+=0.05;
    printf("\nminimum distance : %.2lf\n\n", dis);
        
    dis =0;
    }
}

double grahamScan(point* p, int numOfpoint, int* stack)
{
    double distance=0; // total distance..
    double tempDis=0;
    int tempIndex=0;
    int isCCW=0;
    int i;
    int countFail=0; // count the insert failed
    int countCheck=0; // count the total try
    
    for(i=0; i<=numOfpoint; i++)
    {
        
            if(i==0 || i==1)
            {
                countCheck++;
                stack[i] = i;
                continue;
            }
        if(getAng(p[0].x, p[0].y, p[stack[i-2]].x, p[stack[i-2]].y) <=180)
        {
            isCCW = ccw(p[i-2],p[i-1],p[i]);
        
            if(isCCW == 1)
            {
                stack[i-(countFail)]=i;
                tempIndex = i-(countFail);
            }
            else
            {
                countFail++;
                stack[i-1]=i;
                tempIndex = i-1;
            }
        
            countCheck++;
            if(countCheck==numOfpoint)
            {
                break;
            }
        }
        
        else
        {
            
            
            isCCW = ccw(p[i-2],p[i-1],p[i]);
            
            if(isCCW == -1)
            {
                stack[i-(countFail)]=i;
                tempIndex = i-(countFail);
            }
            else
            {
                countFail++;
                stack[i-1]=i;
                tempIndex = i-1;
            }
            
            countCheck++;
            if(countCheck==numOfpoint)
            {
                break;
            }
        }
    }
    
    //calcultate the distance using stack...//
    for(i=0; i<tempIndex; i++)
    {
        tempDis = getDis(p[stack[i]].x,p[stack[i]].y,p[stack[i+1]].x,p[stack[i+1]].y);
        printf("%d to %d // temp Dis : %.2lf\n",stack[i], stack[i+1], tempDis);
        distance += tempDis;
    }
    tempDis = getDis(p[0].x,p[0].y,p[stack[tempIndex]].x,p[stack[tempIndex]].y);
    printf("%d to %d // temp Dis : %.2lf\n",stack[tempIndex],stack[0],tempDis);
    distance += tempDis;
    //
    
    return distance;
}

void sortByAng(point* p, int numOfPoint)
{
    int i,j;
    double tempX, tempY, tempAng;
    
    for(i=1; i<numOfPoint-1; i++)
    {
        for(j=0; j<numOfPoint-1; j++)
        {
            if(p[j].AngWithStartPoint > p[j+1].AngWithStartPoint)
            {
                tempX = p[j].x;
                p[j].x = p[j+1].x;
                p[j+1].x = tempX;
                
                tempY = p[j].y;
                p[j].y = p[j+1].y;
                p[j+1].y = tempY;
                
                tempAng = p[j].AngWithStartPoint;
                p[j].AngWithStartPoint= p[j+1].AngWithStartPoint;
                p[j+1].AngWithStartPoint = tempAng;
            }
        }
    }
}

//get angle function...
int getAng(double x1, double y1, double x2, double y2)
{
    double result;
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    if((dx>=0)&&(dy==0))
    {
        result =0;
    }
    else
    {
        result = (double)abs(dy) / (double)(abs(dx) + abs(dy));
        
        if((dx<0)&&(dy>=0))
        {
            result = 2-result;
        }
        else if((dx<=0)&&(dy<0))
        {
            result = 2+result;
        }
        else if((dx>0)&&(dy<0))
        {
            result = 4-result;
        }
    }
    return (int)(result*(90.0));
}
//

int ccw(point p1, point p2, point p3)
{
    int result=0;
    
    result=(p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
    if(result>0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

double getDis(double x1, double y1, double x2, double y2)
{
    return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}