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
void add_end(int data,struct node*head){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Memory not available\n");
        return;
    }
    struct node*tail = head;
    if(head==NULL){
        add_beg(data,&head);
        return;
    }
    while(tail->link!=head){
        tail = tail->link;
    }
    tail->link = temp;
    temp->data = data;
    temp->link = head;
}
void print(struct node*head){
    struct node*temp = head;
    while (temp->link!=head){
        printf("%d\n",temp->data);
        temp = temp->link;
    }
    printf("%d",temp->data);
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
    print(head);
    printf("after adding the node in the end\n");
    add_end(0,head);
    print(head);
}