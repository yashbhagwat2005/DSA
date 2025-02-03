#include <stdio.h>
#include <stdlib.h>
struct node{
    int n;
    struct node *link;
};
int main(){
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->n = 10;
    head->link = NULL;
    struct node *element_2 = NULL;
    element_2 = (struct node *)malloc(sizeof(struct node));
    element_2->n = 20;
    element_2->link = NULL;
    head->link = head;
}