#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct point point;
struct point
{
    double x;
    double y;
    int check;
    int index;
};

double getDis(double x1, double y1, double x2, double y2); // getDistance function...
int getAng(double x1, double y1, double x2, double y2); // get Angle function...

int main(void)
{
    int numOfTest=0;
    int numOfPoint=0;
    int i, j;
    int min=360; int startLoc=0; int prevLoc=0;
    int tempAng=0; // save the angel of each step...
    int tempLoc=0; // save the location of each step...
    double tempDis=0; // temp distance of minimum angel...
    double dis=0; // total distance...
    point* p;
    
    
    //input the each information and dynamic allocation...//
    printf("Enter the number of the test : ");
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
    
    numOfPoint++; //automatically, add the start point (0,0)
    
    p = (point*)malloc(sizeof(point)*(numOfPoint));
    
    p[0].x =0; // automatically, set location (0,0) value...
    p[0].y =0; // same as above step
    p[0].index=0; // same as above step
    p[0].check=0; // sames as above step
    
    for(i=1; i<numOfPoint; i++)
    {
        printf("Enter the [%d]loc : ", i);
        scanf("%lf %lf",&p[i].x, &p[i].y);
        p[i].check=0; // set the every check value is '0'...
        p[i].index = i; // set index number each location...
    }
    //
    
    //calculate the needed silk...
    startLoc = 0; // set start location index '0'...
    while(1)
    {
        min = 360;//set min value is max angle(360)...
        for(i=0; i<numOfPoint; i++)
        {
            if(startLoc==i || i==prevLoc)
            {
                continue;
            }
            
            tempAng = getAng(p[startLoc].x, p[startLoc].y, p[i].x, p[i].y);
            if(tempAng == min)
            {
                if(tempDis >= getDis(p[startLoc].x,p[startLoc].y,p[i].x,p[i].y))
                {
                    continue;
                }
            }
            if(tempAng<=min)
            {
                min = tempAng;
                tempLoc = i;
                tempDis = getDis(p[startLoc].x, p[startLoc].y, p[i].x, p[i].y);
            }
        }
        
        if(p[tempLoc].check==1)
        {
            dis += getDis(p[startLoc].x, p[startLoc].y, p[0].x, p[0].y);
            break;
        }
        dis+=getDis(p[startLoc].x, p[startLoc].y, p[tempLoc].x, p[tempLoc].y);
        if(startLoc!=0)
        {
            p[startLoc].check=1;
        }
        printf("[start loc : %d / dest loc : %d]\n",startLoc, tempLoc);
        prevLoc = startLoc;
        startLoc = tempLoc;
    }
    dis+=2;
    //
    
    //dis += 0.05;
    printf("\ntotal dis %.2lf\n\n",dis);
        dis=0;
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

//get distance function...
double getDis(double x1, double y1, double x2, double y2)
{
    return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
}
//