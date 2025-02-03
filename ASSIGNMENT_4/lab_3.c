#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

void array_to_linked_list(struct node* head, int n, int array[], struct node** current) {
    for (int i = 1; i < n; i++) {
        struct node* new = (struct node*)malloc(sizeof(struct node));
        (*current)->link = new;
        new->data = array[i];
        new->link = NULL;
        *current = new;
    }
    (*current)->link = NULL;
}

int hasLoop(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

void print(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->link;
    }
}

int main() {
    int n;
    printf("Enter the number of numbers you want to enter: ");
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &array[i]);
    }
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* current = (struct node*)malloc(sizeof(struct node));
    head->data = array[0];
    head->link = NULL;
    current->data = array[1];
    current->link = NULL;
    head->link = current;
    if (n > 2) {
        array_to_linked_list(head, n, array, &current);
    }
    printf("Contents of the linked list\n");
    print(head);

    int loop = hasLoop(head);
    if (loop) {
        printf("The linked list contains a loop.\n");
    } else {
        printf("The linked list does not contain a loop.\n");
    }

    return 0;
}
