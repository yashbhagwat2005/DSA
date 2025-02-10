#include <stdio.h>
#include <stdbool.h>
#define MAX 100
struct stack {
    int stArr[MAX];
    int top;
};
typedef struct stack STACK;
void create(STACK* s) {
    s->top = -1;
}
void push(STACK* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow Cannot push element.\n");
        return;
    }
    (s->top)+=1;
    s->stArr[s->top] = value; 
    printf("%d pushed onto the stack.\n", value);
}
int pop(STACK* s) {
    if (s->top == -1) {
        printf("Stack Underflow Cannot pop element.\n");
        return -1; 
    }
    (s->top)-=1;
    int poppedValue = s->stArr[s->top];
    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
}
int peek(STACK* s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->stArr[s->top];
}
bool isFull(STACK* s) {
    return s->top == MAX - 1;
}
bool isEmpty(STACK* s) {
    return s->top == -1;
}
int main() {
    STACK myStack;
    create(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    printf("Top element: %d\n", peek(&myStack));
    pop(&myStack);
    pop(&myStack);
    if (isFull(&myStack)){
        printf("Stack overflow\n");
    }
    else{
        printf("The stack is not overflowed \n");
    }
    if (isEmpty(&myStack)){
        printf("The stack is underflowed \n");
    }
    else{
        printf("The stack is not underflowed \n");
    }
    push(&myStack, 101);
    return 0;
}