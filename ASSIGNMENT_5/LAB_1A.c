#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

void add_beg(int data, struct node** head) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    if (*head == NULL) {
        temp->data = data;
        temp->link = temp;
        *head = temp;
        return;
    }

    struct node* tail = *head;
    while (tail->link != *head) {
        tail = tail->link;
    }

    temp->data = data;
    temp->link = *head;
    tail->link = temp;
    *head = temp;
}

void add_end(int data, struct node* head) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not available\n");
        return;
    }

    if (head == NULL) {
        temp->data = data;
        temp->link = temp;
        return;
    }

    struct node* tail = head;
    while (tail->link != head) {
        tail = tail->link;
    }
    temp->data = data;
    tail->link = temp;
    temp->link = head;
}

void print(struct node* head) {
    if (head == NULL) return;

    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("\n");
}

int count(struct node* head) {
    if (head == NULL) return 0;

    int count = 1;
    struct node* temp = head->link;
    while (temp != head) {
        count++;
        temp = temp->link;
    }
    return count;
}

void add_pos(struct node** head, int pos, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    if (*head == NULL) {
        temp->data = data;
        temp->link = temp;
        *head = temp;
        return;
    }

    int list_size = count(*head);

    if (pos == 1) {
        add_beg(data, head);
        free(temp);
        return;
    } else if (pos > list_size + 1 || pos <= 0) {
        printf("Invalid position\n");
        free(temp);
        return;
    } else if (pos == list_size + 1) {
        add_end(data, *head);
        free(temp);
        return;
    } else {
        struct node* current = *head;
        for (int i = 1; i < pos - 1; i++) {
            current = current->link;
        }
        temp->data = data;
        temp->link = current->link;
        current->link = temp;
    }
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory not available \n");
        return 1;
    }
    head->data = 1;
    head->link = head;

    printf("%d\n", head->data);

    add_beg(2, &head);
    printf("After adding at the beginning: %d\n", head->data);
    printf("Second element: %d\n", head->link->data);

    print(head);

    add_end(0, head);
    printf("\n");
    printf("Adding the elemtns in the end\n");
    print(head);

    add_pos(&head, 2, 7);
    printf("Adding the node at 2nd postion\n");
    print(head);

    return 0;
}