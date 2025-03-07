// double linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtHead(struct Node *head, int data){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtPos(struct Node *head, int data, int pos){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node *temp = head;
    int i = 1;
    while(i < pos-1){
        temp = temp->next;
        i++;
    }
    printf("%d", temp->data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void printforward(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printbackward(struct Node *head){
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void main(){
    struct Node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 11);
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 13);
    insertAtEnd(&head, 14);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 16);
    insertAtEnd(&head, 17);
    insertAtEnd(&head, 18);
    insertAtEnd(&head, 19);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 21);
    insertAtEnd(&head, 22);
    insertAtEnd(&head, 23);
    insertAtEnd(&head, 24);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 26);
    insertAtEnd(&head, 27);
    insertAtEnd(&head, 28);
    insertAtEnd(&head, 29);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 31);
    insertAtEnd(&head, 32);
    insertAtEnd(&head, 33);
    insertAtEnd(&head, 34);
    insertAtEnd(&head, 35);
    insertAtEnd(&head, 36);
    insertAtEnd(&head, 37);
    insertAtEnd(&head, 38);
    insertAtEnd(&head, 39);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 41);
    insertAtEnd(&head, 42);
    insertAtEnd(&head, 43);
    insertAtEnd(&head, 44);
    insertAtEnd(&head, 45);
    insertAtEnd(&head, 46);
    insertAtEnd(&head, 47);
    insertAtEnd(&head, 48);
    insertAtEnd(&head, 49);
    printforward(head);
    printbackward(head);
}