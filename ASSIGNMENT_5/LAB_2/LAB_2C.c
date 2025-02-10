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
void print(){
    if (top==-1){
        printf("Stack underflow \n");
        return;
    }
    for (int i = top;i>=0;i--){
        printf("\n %d \n",stack_arr[i]);
    }
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    printf("\nPopped value: %d\n",pop());
    printf("\nPopped value: %d\n",pop());
    print();
}