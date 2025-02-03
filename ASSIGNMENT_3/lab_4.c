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
    int array[4] = {1,2,3,4};
    int size_of_array = sizeof(array)/sizeof(int);
    struct node*head = (struct node*)malloc(sizeof(struct node));
    struct node*current = (struct node*)malloc(sizeof(struct node));
    head->n = array[0];
    head->link = NULL;
    current-> n = array[1];
    current->link = NULL;
    head->link = current;
    for (int i = 2;i<size_of_array;i++){
        struct node*new_node = (struct node*)malloc(sizeof(struct node));
        new_node->n = array[i];
        new_node->link = NULL;
        current->link  = new_node;
        current = new_node;
    }
    print(head);
}