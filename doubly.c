// wap to

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory Allocation Failed");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    display(head);
    // insertAtHead(&head, 0);
    // display(head);
    // insertAfter(,4);
    // print(head);
    return 0;
    // int* arr=;
    // free(arr);
}