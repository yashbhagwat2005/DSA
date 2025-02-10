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
int is_empty(){
    if (top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){
    int value;
    if (is_empty()==1){
        printf("Stack underflow \n");
        exit(0);
    }
    value = stack_arr[top];
    top-=1;
    return value;  
}
int peek(){
    int value;
    value = stack_arr[top];
    return value;
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    printf("\nPopped value: %d\n",pop());
    printf("\nPopped value: %d\n",pop());
    pop();
    int data = peek();
    printf("Top data element of the stack: %d",data);

}