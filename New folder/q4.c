// Given a singly linked list, write a function to swap elements pairwise.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node *swapPairs(struct Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    struct Node *dummy = (struct Node *)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node *prev = dummy;
    while (head && head->next)
    {
        struct Node *first = head;
        struct Node *second = head->next;
        prev->next = second;
        first->next = second->next;
        second->next = first;
        prev = first;
        head = first->next;
    }
    struct Node *new_head = dummy->next;
    free(dummy);
    return new_head;
}

void printList(struct Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("None\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    struct Node *head = NULL;
    struct Node *current = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        if (head == NULL)
        {
            head = createNode(val);
            current = head;
        }
        else
        {
            current->next = createNode(val);
            current = current->next;
        }
    }
    printf("Original Linked List:\n");
    printList(head);
    struct Node *new_head = swapPairs(head);
    printf("Linked List after swapping elements pairwise:\n");
    printList(new_head);
    while (new_head)
    {
        struct Node *temp = new_head;
        new_head = new_head->next;
        free(temp);
    }
    return 0;
}
