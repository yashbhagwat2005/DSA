#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node*link;
};
void array_to_linked_list(struct node*head,int n,int array[],struct node **current){
    for (int i = 2;i<n;i++){
        struct node*new = (struct node*)malloc(sizeof(struct node));
        (*current)->link = new;
        new->data = array[i];
        new->link = NULL;
        *current = new;
    }
    (*current)->link = NULL;
}
void rotate(struct node**head,int k,int count){
    if (k==0){
        return;
    }
    k = k%count;
    if (k==0){
        return;
    }
    struct node*current = *head;
    for (int i =1;i<k;i++){
        current = current->link;
    }
    struct node*new_head = current->link;
    current->link = NULL;
    struct node*temp = new_head;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = (*head);
    *head = new_head; 
}
void print(struct node *head){
    struct node *temp;
    temp = head;
    while (temp!=NULL){
        printf("%d \n",temp->data);
        temp = temp->link;
    }
}
int main(){
    int n;
    printf("Enter the number of numbers you want to enter(more than 1): ");
    scanf("%d",&n);
    int array[n];
    for (int i = 0;i<n;i++){
        printf("Enter a number: ");
        scanf("%d",&array[i]);
    }
    struct node*head = (struct node*)malloc(sizeof(struct node));
    struct node*current = (struct node*)malloc(sizeof(struct node));
    head->data = array[0];
    head->link = NULL;
    current->data = array[1];
    current->link = NULL;
    head->link = current;
    if (n>2){
        array_to_linked_list(head,n,array,&current);
    }
    printf("Contents of the single linekd list\n");
    print(head);
    int k;
    printf("Enter an integer to roate the linked list: ");
    scanf("%d",&k);
    rotate(&head,k,n);
    print(head);

}