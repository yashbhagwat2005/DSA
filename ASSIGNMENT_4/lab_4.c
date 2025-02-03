#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

void insert_at_first(struct node** head, int new_data) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = new_data;
    new->prev = NULL;
    new->next = *head;
    if (*head != NULL) {
        (*head)->prev = new;
    }
    *head = new;
}

void insert_at_end(struct node** head, int new_data) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;
    new->data = new_data;
    new->next = NULL;
    if (*head == NULL) {
        new->prev = NULL;
        *head = new;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
}

void insert_at_middle(struct node** head, int new_data) {
    struct node* slow = *head;
    struct node* fast = *head;
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = new_data;
    if (*head == NULL) {
        new->prev = NULL;
        new->next = NULL;
        *head = new;
        return;
    }
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    new->next = slow;
    new->prev = slow->prev;
    if (slow->prev != NULL) {
        slow->prev->next = new;
    } else {
        *head = new;
    }
    slow->prev = new;
}

void insert_after_node(struct node** head, int given_node, int new_data) {
    struct node* temp = *head;
    while (temp != NULL && temp->data != given_node) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = new_data;
    new->next = temp->next;
    new->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = new;
    }
    temp->next = new;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insert_at_first(&head, 20);
    insert_at_first(&head, 10);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_middle(&head, 25);
    insert_after_node(&head, 30, 35);
    display(head);
    return 0;
}
