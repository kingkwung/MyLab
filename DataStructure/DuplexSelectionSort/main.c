//
//  main.c
//  DATASTRUCTURE_DuplexSelectionSort_20140501
//
//  Created by Youngnam Woo on 2014. 5. 1..
//  Copyright (c) 2014년 Youngnam Woo. All rights reserved.
//

#include <stdio.h>

typedef struct bundle bundle;
struct bundle{
    int max;
    int max_idx;
    int min;
    int min_idx;
};

int main(int argc, const char * argv[])
{
    int size=8;
    int list[size];
    int i, j;
    int temp1, temp2;
    bundle bun;
    bun.max=0;
    bun.min=1000;
    
    for(i=0; i<size; i++){ //initialization..
        list[i]=0;
    }
    
    /*
    for(i=0; i<size; i++){ //input the value..
        printf("Enter the number : ");
        scanf("%d",&list[i]);
    }
    */
    
    ///*
    list[0]=22;
    list[1]=25;
    list[2]=7;
    list[3]=3;
    list[4]=30;
    list[5]=11;
    list[6]=14;
    list[7]=8;
    //*/
    
    printf("origin : ");
    for(i=0; i<size; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    
    
    for(j=0; j<size; j++){
        for(i=0; i<size-j; i++){
            if(list[i] > bun.max){
                bun.max = list[i];
                bun.max_idx = i;
            }
        }
        
        if(bun.max > list[i]){
            temp1 = list[i];
            list[i] = bun.max;
            list[bun.max_idx] = temp1;
        }
        
        
        for(i=size-1; i>j; i--){

            if(list[i] < bun.min){
                bun.min = list[i];
                bun.min_idx = i;
            }
        }
        
        if(bun.min < list[i]){
            temp2 = list[i];
            list[i] = bun.min;
            list[bun.min_idx] = temp2;
        }
        
        
        
        
        bun.max=0;
        bun.min=1000;
        
        printf(" ->  ");
        for(i=0; i<size; i++){
            printf("%d ", list[i]);
        }
        printf("\n");
        
        
    }


}

