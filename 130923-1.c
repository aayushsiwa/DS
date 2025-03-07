// wap to create a single linked list insert node at beginning, end, any position

#include <stdio.h>
#include <stdlib.h>
// #include "bootstrap.c"

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

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

void insertAtHead(struct node **head, int val)
{
    struct node *newNode = createNode(val);
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertInMiddle(struct node **head, int val){
    struct node *newNode=createNode(val);
    struct node *temp=*head;
    int len=0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    free(temp);
    int pos=len/2;
    printf("pos=%d\n",pos);
    struct node *temp1=*head;
    for(int i=0;i<pos;i++){
        temp1=temp1->next;
    }
    newNode->next=temp1->next;
    temp1->next=newNode;
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

void deleteHead(struct node *head)
{
    (head) = (head)->next;
}

void deleteEnd(struct node *head)
{
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

void print(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtHeadIn(struct node **head)
{
    // // struct node *head = NULL;
    int a;
    // // printf("Enter the number of nodes:- ");
    // // scanf("%d", &n);
    // // for (int i = 0; i < n; i++)
    // // {
    // //     printf("%d- ", n - i);
    // //     scanf("%d", &a);
    // //     insertAtHead(&head, a);
    // // }
    printf("Element:- ");
    scanf("%d", &a);
    insertAtHead(head, a);
    print(head);
}

int insertInMiddleIn(struct node **head){
    int a;
    printf("Element:- ");
    scanf("%d",&a);
    insertInMiddle(head,a);
    print(head);
}

int insertAtEndIn(struct node **head){
    int a;
    printf("Element:- ");
    scanf("%d",&a);
    insertAtEnd(head,a);
    print(head);
}

int main()
{
    int n, i, pos, ele, choice;
    while (1)
    {
        printf("\n1->Insert an element at head");
        // printf("\n2->Delete element at specific position");
        printf("\n2->Insert element at end");
        // printf("\n3->Linear search");
        printf("\n3->Insert element in the middle of the list");
        printf("\n4->Traversal of array");
        printf("\n5->Exit");
        printf("\nEnter choice- ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            insertAtHeadIn(&head);
            break;
        case 2:
            // delete_element(arr, n);
            insertAtEndIn(&head);
            break;
        case 3:
            // search(arr, n);
            insertInMiddleIn(&head);
            break;
        case 4:
            // print_array(arr, n);
            print(&head);
            printf("\n---------------xxx---------------\n");
            break;
        case 5:
            return 0;
        }
    }
}
