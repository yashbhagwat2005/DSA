#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4
int stack_arr[MAX];
int top = -1;

// ... (push, pop, and is_full functions remain the same)

int main() {
    push(1);
    push(2);
    push(3);
    push(4);  // Stack is now full

    if (is_full()) {  // Check if full *before* popping
        printf("The stack is full\n"); // This WILL print now
    } else {
        printf("The stack is not full\n"); // This won't print
    }

    printf("\nPopped value: %d\n", pop());
    printf("\nPopped value: %d\n", pop()); // Now stack has 2 elements

    if (is_full()) { // Check if full *after* popping
        printf("The stack is full\n"); // This won't print now
    } else {
        printf("The stack is not full\n"); // This WILL print now
    }

    push(3);
    push(4); // Now the stack will be full again

    if (is_full()){
        printf("The stack is full\n"); // This WILL print now
    }
    else{
        printf("The stack is not full\n");
    }

    return 0;
}