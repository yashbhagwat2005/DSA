#include <stdio.h>
#include <stdlib.h>
struct node {
    int n;
    struct node*link;
};
int main(){
    struct node*head = (struct node*)malloc(sizeof(struct node));
    struct node*current = (struct node*)malloc(sizeof(struct node));
    head->n = 11;
    head->link = NULL;
    current->n = 12;
    current->link = NULL;
    head->link = current;
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    printf("Displaying the single link list \n");
    while (temp!=NULL){
        printf("%d \n",temp->n);
        temp = temp->link;  
    }
}