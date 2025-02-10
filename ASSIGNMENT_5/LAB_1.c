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

void del_beg(struct node** head) {
    if (*head == NULL) return; 
    struct node* tail = *head;
    while (tail->link != *head) {
        tail = tail->link;
    }
    if (*head == tail) {
        free(*head);
        *head = NULL;
        return;
    }
    tail->link = (*head)->link;
    free(*head);
    *head = tail->link;
}

void del_end(struct node** head) {
    if (*head == NULL) return;

    if ((*head)->link == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* current = *head;
    struct node* previous = NULL;
    while (current->link != *head) {
        previous = current;
        current = current->link;
    }
    previous->link = *head;
    free(current);
}


void add_end(int data, struct node** head) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not available\n");
        return;
    }
    temp->data = data;
    temp->link = temp; 

    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct node* tail = *head;
    while (tail->link != *head) {
        tail = tail->link;
    }
    tail->link = temp;
    temp->link = *head;
}

void print(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("\n");
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
        add_end(data, head);
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
    struct node* head = NULL;
    int n;
    int pos;
    printf("Enter a number to add a head node in the linked list: ");
    scanf("%d",&n);
    add_beg(n,&head);
    int ch;
    printf("Menu \n");
    printf("1.Insert an element at a specific posiotion \n");
    printf("2.Insert an element at the beginning of the list\n");
    printf("3.Insert an element at the end of the list.\n");
    printf("4.Delete an element from a specific position specified by the user.\n");
    printf("5.Delete the first element from the list.\n");
    printf("6.Delete the last element from the list.\n");
    printf("0.To exit the program.\n");
    printf("Enter an appropriate number: ");
    scanf("%d",&ch);
    while (ch!=0){
        if (ch==1){
            printf("Enter a number to add it in the specific position: ");
            scanf("%d",&pos);
            printf("Enter a number : ");
            scanf("%d",&n);
            add_pos(&head,pos,n);
        }
        else if(ch==2){
            printf("Enter a number to add it in the beginning of the list: ");
            scanf("%d",&n);
            add_beg(n,&head);
        }
        else if(ch==3){
            printf("Enter a number to add it in the end of the list : ");
            scanf("%d",&n);
            add_end(n,&head);
        }
        else if (ch==4){
            printf("Enter a number to delete it in the specific position: ");
            scanf("%d",&pos);
            del_pos(&head,pos,count(head));
        }
        else if (ch==5){
            printf("Deleting the first element of the list\n");
            del_beg(&head);
        }
        else if (ch==6){
            printf("Delete the last element of the list\n");
            del_end(&head);
        }
        else{
            printf("Enter an appropriate number\n");
        }
        printf("Content of the linked list after making the changes \n");
        print(head);
        printf("Enter your next choice: ");
        scanf("%d",&ch);
    }
    printf("\nEnd of program\n");
    return 0;
}