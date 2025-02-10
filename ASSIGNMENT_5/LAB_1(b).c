#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*link;
};
void add_beg(int data,struct node**head){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    if (*head==NULL){
        temp->data = data;
        temp->link = temp;
        *head = temp;
        return;
    }
    struct node*tail = (*head);
    while (tail->link!=*head){
        tail = tail->link;
    }
    temp->data = data;
    temp->link = *head;
    tail->link = temp;
    *head = temp;
}
int main(){
    struct node*head = (struct node*)malloc(sizeof(struct node));
    if (head==NULL){
        printf("Memory not available \n");
        return 1;
    }
    head->data = 1;
    head->link = head;
    struct node*tail = head;
    printf("%d\n",(tail->data));
    add_beg(2,&head);
    printf("after adding the node in the begginning\n");
    printf("%d\n",(head->data));  
    printf("%d\n",(head->link->data));
}