#include <stdio.h>
#include <stdlib.h>
struct node{
    int n;
    struct node* link;
};
void add_new_head(struct node **head,int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->n = data;
    ptr->link = *head;
    *head = ptr;
}
void print(struct node *head){
    struct node *temp;
    temp = head;
    printf("The current head's data is %d \n",temp->n);
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
    printf("The intial single linked is before adding a new head \n");
    print(head);
    add_new_head(&head,23);
    printf("THe updated single linked list after adding a new head \n");
    print(head);

}