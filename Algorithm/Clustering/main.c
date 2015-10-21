//와일문멈추는 조건은 잘 되었다..
//클러스터링, 셋 센터 두 개의 조건이 잘못되었다..
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct dot dot;
struct dot
{
    double x;
    double y;
    int belonged_index;
    double total_dis;
};

dot temp_standard_point[3];

double distance(dot a, dot b) // get distance function..
{
    double x1 = a.x;
    double y1 = a.y;
    double x2 = b.x;
    double y2 = b.y;
    
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

void clustering(dot* loc, dot* standard_point, int numOfDot) // assign cluster of each location..
{
    int i, j;
    double min = 1000000;
    
    for(i=0; i<numOfDot; i++){
        min = 1000000;
        for(j=0; j<3; j++){
            if(min>distance(loc[i], standard_point[j])){
                loc[i].belonged_index = j;
                min = distance(loc[i], standard_point[j]);
            }
        }
    }
}

void setCenterPoint(dot* loc, dot* standard_point, int numOfDot) // reset the location of 'center point' of each cluster..
{

    int i, j;
    double min = 100000;
    
    for(i=0; i<numOfDot; i++)
    {
        for(j=0; j<numOfDot; j++)
        {
            if(loc[i].belonged_index==0 && loc[j].belonged_index==0)
            {
                loc[i].total_dis += distance(loc[i], loc[j]);
            }
            if(loc[i].belonged_index==1 && loc[j].belonged_index==1)
            {
                loc[i].total_dis += distance(loc[i], loc[j]);
            }
            if(loc[i].belonged_index==2 && loc[j].belonged_index==2)
            {
                loc[i].total_dis += distance(loc[i], loc[j]);
            }
        }
    }
    
    
    for(i=0; i<3; i++)
    {
        for(j=0; j<numOfDot; j++)
        {
            if(loc[j].belonged_index==i)
            {
                if(min>loc[j].total_dis)
                {
                    temp_standard_point[i] = loc[j];
                    min = loc[j].total_dis;
                }
            }
        }
        min = 100000;
    }
    
}

int main(void)
{
    int i;
    int numOfDot; // number of dot
    dot* loc;
    dot standard_point[3];
    
    
    printf("Enter the number : "); // enter the numberm of dots
    scanf("%d",&numOfDot);
    loc = (dot*)malloc(sizeof(dot)*numOfDot); // memory allocation
    
    for(i=0; i<numOfDot; i++){
        loc[i].belonged_index = -1;
        loc[i].total_dis = 0;
    }
    
     for(i=0; i<numOfDot; i++){
     printf("Enter the %d's location : ", i+1);
     scanf("%lf %lf",&loc[i].x, &loc[i].y);
     }

    /*
    //test case..
    loc[0].x = 1; loc[1].x = 5; loc[2].x = 8;
    loc[3].x = 9; loc[4].x = 10; loc[5].x = 3;
    loc[6].x = 1; loc[7].x = 1; loc[8].x = 1;
    loc[9].x = 7; loc[10].x = 4; loc[11].x = 1;
    loc[12].x = 8; loc[13].x = 1; loc[14].x = 6;
    loc[15].x = 15; loc[16].x = 7; loc[17].x = 1;
    loc[18].x = 8; loc[19].x = 1; loc[20].x = 17;
    loc[21].x = 4; loc[22].x = 5; loc[23].x = 5;
    loc[24].x = 1; loc[25].x = 4; loc[26].x = 1;
    loc[27].x = 3; loc[28].x = 1; loc[29].x = 2;
    
    loc[0].y = 1; loc[1].y = 7; loc[2].y = 17;
    loc[3].y = 6; loc[4].y = 11; loc[5].y = 14;비
    loc[6].y = 3; loc[7].y = 12; loc[8].y = 12;
    loc[9].y = 1; loc[10].y = 1; loc[11].y = 1;
    loc[12].y = 2; loc[13].y = 1; loc[14].y = 12;
    loc[15].y = 12; loc[16].y = 5; loc[17].y = 5;
    loc[18].y = 4; loc[19].y = 1; loc[20].y = 1;
    loc[21].y = 1; loc[22].y = 15; loc[23].y = 8;
    loc[24].y = 6; loc[25].y = 1; loc[26].y = 14;
    loc[27].y = 15; loc[28].y = 7; loc[29].y = 1;

    //*/
    
    
    //input the starting points..
    standard_point[0] = loc[12];
    standard_point[1] = loc[13];
    standard_point[2] = loc[14];
    
    while(1)
    {
        clustering(loc, standard_point, numOfDot); // doing clustering..
        setCenterPoint(loc, standard_point, numOfDot); // reset the location of 'center point' of each cluster..
        
        if(standard_point[0].x==temp_standard_point[0].x && standard_point[0].y==temp_standard_point[0].y && standard_point[1].x==temp_standard_point[1].x && standard_point[1].y==temp_standard_point[1].y && standard_point[2].x==temp_standard_point[2].x && standard_point[2].y==temp_standard_point[2].y)
        {
            break;
        }
        
        standard_point[0]=temp_standard_point[0];
        standard_point[1]=temp_standard_point[1];
        standard_point[2]=temp_standard_point[2];
    }
    
    
    //print the result..
    printf("\n[A]\n");
    for(i=0; i<numOfDot; i++)
    {
        if(loc[i].belonged_index==0)
            printf("%.0lf, %.0lf\n",loc[i].x,loc[i].y);
    }
    printf("\n[B]\n");
    for(i=0; i<numOfDot; i++)
    {
        if(loc[i].belonged_index==1)
            printf("%.0lf, %.0lf\n",loc[i].x,loc[i].y);
    }
    printf("\n[C]\n");
    for(i=0; i<numOfDot; i++)
    {
        if(loc[i].belonged_index==2)
            printf("%.0lf, %.0lf\n",loc[i].x,loc[i].y);
    }
    printf("\nCENTER POINT OF EACH CLUSTER..\n");
    for(i=0; i<3; i++)
        printf("[%0.lf,%0.lf]\n",standard_point[i].x,standard_point[i].y);
}