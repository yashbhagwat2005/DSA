#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top = -1;
void push(int data){
    if (top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    top+=1;
    stack_arr[top] = data;
}
int pop(){
    if (top==-1){
        printf("Stack underflow \n");
        exit(1);
    }
    int value = stack_arr[top];
    top-=1;
    return value;  
}
int is_full(){
    if (top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    printf("\nPopped value: %d\n",pop());
    printf("\nPopped value: %d\n",pop());
    push(3);
    push(4);
    if (is_full()==1){
        printf("The stack is overflowed \n");
    }
    else{
        printf("There is space \n");
    }
    
    
}