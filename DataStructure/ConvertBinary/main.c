/*
 This program converts decimal number into binary number using stack(push, pop).
 
 Input : decimal number
 Output : binary number
 
 2014/03/28, Made by 우영남
 */
#include<stdio.h>
#include<stdlib.h>

void push(int remainer); // function declaration of 'push'
void pop(); // function declaration of 'pop'

int stack[100]; // stack array..
int idx=0; // stack index

int main(void)
{
    int decimal=0; // save the input value
    int remainder=0; // save the remainder
    
    
    printf("Enter the DECIMAL number : ");
    scanf("%d",&decimal);
    
    printf("\nInput value(DECIMAL) : %d\n",decimal);
    
    while(decimal!=1){ // If decimal is '1', break the roop
        remainder = decimal%2;
        decimal = decimal/2;
        
        push(remainder); // call push function (input : remainder, output : none)
        
        if(decimal == 1){ // If decimal is '1' call the push function last
            push(decimal);
            idx--;
        }
    }
    
    printf("Output value(BINARY) : ");
    while(idx>=0){
        pop(); // call the pop function (input : none , output : none)
    }
    
    printf("\n\n[System terminated]");
}


/*
 It is push funtion.
 This function recieve the 'remainder' and save it into a stack.
 After that, idx will increase 1..
 
 Input : remainder(remainder of each step)
 Output : none
 */
void push(int remainder){
    stack[idx++]=remainder;
}

/*
 It is pop funtion
 This function will pop the upper value of a stack.
 After the pop, index will decrease '1'..
 
 Input : none
 Output : none
 */
void pop(){
    printf("%d",stack[idx]);
    stack[idx]=NULL;
    idx--;
}
