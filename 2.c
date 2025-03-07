#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct node **head, int val)
{
    struct node *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(struct node **head, int val)
{
    struct node *newNode = createNode(val);
    // newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

// void insertAfter(struct node* prevNode, int val)
// {
//     if(prevNode==NULL){
//         printf("Previous node cannot be NULL\n");
//         return;
//     }
//     struct node *newNode = createNode(val);
//     newNode->data=val;
//     newNode->next=prevNode->next;
//     prevNode->next=newNode;
// }

void insertAfter(struct node *head,int pos, int val)
{
    struct node *prevNode = head;
    if (head == NULL)
    {
        head->data=val;
        head->next=NULL;
        return;
    }
    for(int i=0;i<pos-1;i++){
        prevNode=prevNode->next;
    }
    printf("%d\n",prevNode->data);
    struct node *newNode = createNode(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    print(head);
    insertAtHead(&head, 0);
    print(head);
    insertAfter(head,1,5);
    print(head);
    return 0;
}
