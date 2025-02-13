#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};
void push(struct node** top, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Stack overflow \n");
        exit(1);
    }
    new_node->data = value;
    new_node->link = *top;
    *top = new_node;
    printf("%d pushed onto the stack.\n", value);
}
void pop(struct node** top) {
    if (*top == NULL) {
        printf("Stack underflow \n");
        return;
    }
    struct node* temp = *top;
    printf("%d popped from the stack.\n", temp->data);
    *top = (*top)->link; 
    free(temp);
}
int peek(struct node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int is_empty(struct node* top) {
    return (top == NULL);
}

int main() {
    struct node* top = NULL;
    if (is_empty(top)) {
        printf("Stack is empty\n");
    }
    push(&top, 1);
    push(&top, 2);
    printf("Top element: %d\n", peek(top));
    pop(&top);
    pop(&top);
    if (is_empty(top)) {
        printf("Stack is empty\n");
    }
}