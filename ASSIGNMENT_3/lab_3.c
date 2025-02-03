#include<stdio.h>
#include<stdlib.h>
struct node {
    int n;
    struct node*link;
};
void print(struct node *head){
    struct node *temp;
    temp = head;
    while (temp!=NULL){
        printf("%d \n",temp->n);
        temp = temp->link;
    }
}
int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* current = (struct node*)malloc(sizeof(struct node));
    head->n = 11;
    head->link = NULL;
    current->n = 12;
    current->link = NULL;
    head->link = current;
    printf("Displaying the single link list \n");
    print(head);
}