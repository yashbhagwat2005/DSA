#include<stdio.h>
#include<stdlib.h>
struct node {
    int n;
    struct node*link;
};
int count_nodes(struct node* head){
    struct node* temp = head;
    int count = 1;
    while (temp->link!= NULL){
        count++;
        temp = temp->link;
    }
    return count;


}
void linked_list_array(int count,struct node*head,int array[]){
    struct node* temp = head;
    for (int i = 0;i<count;i++){
        array[i] = temp->n;
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
    current = (struct node*)malloc(sizeof(struct node));
    current->n = 11;
    current->link = NULL;
    head->link->link = current;
    int count = count_nodes(head);
    int array[count];
    linked_list_array(count,head,array);
    for (int i = 0;i<count;i++){
        printf("%d\n",array[i]);
    }
}