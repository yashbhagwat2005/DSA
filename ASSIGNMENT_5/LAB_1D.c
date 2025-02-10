#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*link;
};
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
void del_beg(struct node**head){
    struct node*tail = *head;
    while(tail->link!=(*head)){
        tail = tail->link;
    }
    tail->link = (*head)->link;
    free(*head);
    *head = tail->link;
}
void del_end(struct node**head){
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    if ((*head)->link == *head) { 
        free(*head);
        *head = NULL;
        return;
    }
    struct node*current = *head;
    struct node*previous = NULL;
    while(current->link!=*head){
        previous = current;
        current = current->link;
    }
    previous->link = *head;
    free(current);
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
void del_pos(struct node**head,int pos,int n){
    if (*head==NULL){
        printf("List is empty");
        return;
    }
    if (pos==0 || pos>(n+1)){
        printf("Enter an appropriate position \n");
        return;
    }
    if (pos==1){
        del_beg(head);
        return;
    }
    if (pos==n+1){
        del_end(head);
        return;
    }
    struct node*previous = NULL;
    struct node*current = (*head);
    for (int i = 1;i<=(pos-1);i++){
        previous = current;
        current = current->link;

    }
    previous->link = current->link;
    free(current);
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
    int pos;
    printf("Enter the postion: ");
    scanf("%d",&pos);
    del_pos(&head,pos,n);
    printf("After deleting the particular postion node\n");
    print(head);

}