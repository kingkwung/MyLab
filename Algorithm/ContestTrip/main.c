
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct courseInfo courseInfo;
struct courseInfo
{
    char** line;
};

void findWay(courseInfo* courses, char* departureCity, char* arrivalCity, int numOfCourses, int numOfStation);

int main(void)
{
    int i, j;
    int numOfTest=0;
    int numOfCity=0;
    int numOfCourse=0;
    int numOfStation=0;
    int dooroutTime=0;
    courseInfo* courses;
    char** cityList;
    char departureCity[20];
    char arrivalCity[20];
    
    ////
    printf("Enter the number of TEST : ");
    scanf("%d",&numOfTest);
    
    printf("Enter the number of CITY : ");
    scanf("%d",&numOfCity);
    printf("\n");
    ////
    
    ////
    cityList = (char**)malloc(sizeof(char*)*numOfCity);
    for(i=0; i<numOfCity; i++)
    {
        cityList[i] = (char*)malloc(sizeof(char)*20);
    }
    
    for(i=0; i<numOfCity; i++)
    {
        printf("Enter the [%d's CITYNAME] : ", i+1);
        getchar();
        scanf("%[^\n]", cityList[i]);
    }
    printf("\n");
    ////
    
    ////
    printf("Enter the number of Train Course : ");
    scanf("%d", &numOfCourse);
    printf("\n");
    ////
    
    ////
    courses = (courseInfo*)malloc(sizeof(courseInfo)*numOfCourse);
    
    for(i=0; i<numOfCourse; i++)
    {
        printf("Enter the NUMBER of the STAIONS of [%d's course] : ", i+1);
        scanf("%d", &numOfStation);
        
        courses[i].line = (char**)malloc(sizeof(char*)*(numOfStation*2));
        
        for(j=0; j<numOfStation*2; j++)
        {
            courses[i].line[j] = (char*)malloc(sizeof(char)*10);
        }
        
       
        for(j=0; j<numOfStation*2; j++)
        {
            if(j%2==0)
            {
                printf("Enter the DEPARTURE(arrival)TIME of %d's course : ",i+1);
            }
            else
            {
                printf("Enter the CITY NAME of THAT : ");
            }
            getchar();
            scanf("%[^\n]",courses[i].line[j]);
        }
        printf("\n");
    }
    ////
    
    ////
    printf("Enter the time of the HOME DEPARTURE : ");
    scanf("%d", &dooroutTime);
    printf("\n");
    ////
    
    ////
    printf("Enter the DEPARTURE CITY : ");
    getchar();
    scanf("%[^\n]", departureCity);
    printf("Enter the ARRIVAL CITY : ");
    getchar();
    scanf("%[^\n]", arrivalCity);
    printf("\n");
    ////
    
    findWay(courses, departureCity, arrivalCity, numOfCourse, numOfStation);
}

void findWay(courseInfo* courses, char* departureCity, char* arrivalCity, int numOfCourses, int numOfStation)
{
    int i;
    char* findName = departureCity;
    
    for(i=0; i<numOfCourses; i++)
    {
        if(strcmp(findName, courses[i].line[3])==0)
        {
            printf("SFSDFSDFSDFSDF");
        }
    }
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct courseInfo courseInfo;
struct courseInfo
{
    char** course;
};

int main(void)
{
    int i, j;
    int numOfTest=0;
    int numOfCity=0;
    int numOfCourse=0;
    int numOfStation=0;
    int dooroutTime=0;
    courseInfo* courses;
    char** cityList;
    char departureCity[20];
    char arrivalCity[20];
    
    ////
    printf("Enter the number of TEST : ");
    scanf("%d",&numOfTest);
    
    printf("Enter the number of CITY : ");
    scanf("%d",&numOfCity);
    printf("\n");
    ////
    
    ////
    cityList = (char**)malloc(sizeof(char*)*numOfCity);
    for(i=0; i<numOfCity; i++)
    {
        cityList[i] = (char*)malloc(sizeof(char)*20);
    }
    
    for(i=0; i<numOfCity; i++)
    {
        printf("Enter the [%d's CITYNAME] : ", i+1);
        getchar();
        scanf("%[^\n]", cityList[i]);
    }
    printf("\n");
    ////
    
    ////
    printf("Enter the number of Train Course : ");
    scanf("%d", &numOfCourse);
    printf("\n");
    ////
    
    ////
    courses = (courseInfo*)malloc(sizeof(courseInfo)*numOfCourse);

    for(i=0; i<numOfCourse; i++)
    {
        printf("Enter the NUMBER of the STAIONS of [%d's course] : ", i+1);
        scanf("%d", &numOfStation);
        
        courses[i].course = (char**)malloc(sizeof(char*)*numOfStation);
        for(j=0; j<numOfStation; j++)
        {
            courses[i].course[j] = (char*)malloc(sizeof(char)*30);
        }
        
        for(j=0; j<numOfStation; j++)
        {
            printf("Enter the ARRIVAL(departure)TIME and CITYNAME : ");
            getchar();
            scanf("%[^\n]", courses[i].course[j]);
        }
        printf("\n");
    }
    ////
    
    ////
    printf("Enter the time of the HOME DEPARTURE : ");
    scanf("%d", &dooroutTime);
    printf("\n");
    ////
    
    ////
    printf("Enter the DEPARTURE CITY : ");
    getchar();
    scanf("%[^\n]", departureCity);
    printf("Enter the ARRIVAL CITY : ");
    getchar();
    scanf("%[^\n]", arrivalCity);
    printf("\n");
    ////
    
    
}
*/


