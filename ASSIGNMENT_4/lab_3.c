#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* link;
};

void array_to_linked_list(int n, struct node** head, int array[]) {
    *head = (struct node*)malloc(sizeof(struct node));
    (*head)->data = array[0];
    (*head)->link = NULL;

    struct node* current = *head;

    for (int i = 1; i < n; i++) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = array[i];
        new_node->link = NULL;
        current->link = new_node;
        current = new_node;
    }
}

int loop_create(struct node* head, int pos1, int pos2) {
    struct node* node1 = head;
    struct node* node2 = head;

    for (int i = 1; i < pos1; i++) {
        node1 = node1->link;
    }
    for (int i = 1; i < pos2; i++) {
        node2 = node2->link;
    }

    node1->link = node2;

    return 1;
}

int detect_loop(struct node* head) {
    struct node *slow = head, *fast = head;

    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number of numbers you want to enter (enter more than 1): ");
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &array[i]);
    }

    srand(time(NULL));
    int value = rand() % 2;

    struct node* head = NULL;

    array_to_linked_list(n, &head, array);

    if (value == 0) {
        printf("No loop created.\n");
        if (detect_loop(head)) {
            printf("List has a loop.\n");
        } else {
            printf("List has no loop.\n");
        }
    } else {
        int pos1, pos2;
        printf("\nEnter a number pos1: ");
        scanf("%d", &pos1);
        printf("\nEnter a number pos2: ");
        scanf("%d", &pos2);

        if (loop_create(head, pos1, pos2)) {
            printf("Loop created successfully.\n");
            if (detect_loop(head)) {
                printf("List has a loop.\n");
            } else {
                printf("Error: Loop was not created.\n");
            }
        } else {
            printf("Invalid input or positions out of range.\n");
        }
    }

    return 0;
}