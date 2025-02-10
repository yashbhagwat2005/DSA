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
void add_end(int data,struct node**head){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not available\n");
        return;
    }
    temp->data = data;
    if (*head == NULL) {
        temp->link = temp;
        *head = temp;
        return;
    }
    struct node *tail = *head;
    while (tail->link != *head) {
        tail = tail->link;
    }
    temp->link = *head;
    tail->link = temp;
}
void print(struct node*head){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->link;
    } while (temp != head);
}
void del_beg(struct node**head){
    struct node*tail = *head;
    while(tail->link!=(*head)){
        tail = tail->link;
    }
    tail->link = (*head)->link;
    free(*head);
    *head = tail->link;
}

int main(){
    int n;
    printf("Enter the number of numbers you want to enter: ");
    scanf("%d",&n);
    int array[n];
    struct node*head = NULL;
    for (int i = 0;i<n;i++){
        printf("Enter a number: ");
        scanf("%d",&array[i]);
    }
    for (int i = 0;i<n;i++){
        add_end(array[i],&head);
    }
    printf("Content of the linked list \n");
    print(head);
    free(array);
    del_beg(&head);
    printf("After deleting the fist element\n");
    print(head);
}