#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *arbitrary;
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
    newNode->arbitrary = NULL;
    return newNode;
}

void duplicateLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        struct Node *newNode = createNode(current->data);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }
}

void updateArbitraryPointers(struct Node *head)
{
    struct Node *current = head;
    struct Node *maxNode = NULL;
    while (current != NULL)
    {
        if (maxNode == NULL || current->data > maxNode->data)
        {
            maxNode = current;
        }
        else
        {
            current->arbitrary = maxNode;
        }
        current = current->next;
    }
}

struct Node *splitLinkedList(struct Node *head)
{
    struct Node *originalHead = head;
    struct Node *newHead = head->next;
    struct Node *current = originalHead;
    while (current != NULL)
    {
        struct Node *nextOriginal = current->next->next;
        if (nextOriginal != NULL)
        {
            current->next->next = nextOriginal->next;
        }
        else
        {
            current->next->next = NULL;
        }
        current->next = nextOriginal;
        current = nextOriginal;
    }
    return newHead;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->arbitrary != NULL)
        {
            printf(" (Arbitrary: %d)", head->arbitrary->data);
        }
        printf(" -> ");
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = createNode(5);
    head->next = createNode(2);
    head->next->next = createNode(10);
    head->next->next->next = createNode(1);
    head->arbitrary = head->next->next;
    head->next->arbitrary = head;
    head->next->next->arbitrary = head->next->next->next;
    head->next->next->next->arbitrary = head->next;
    printf("Original Linked List:\n");
    printList(head);
    duplicateLinkedList(head);
    updateArbitraryPointers(head);
    struct Node *newHead = splitLinkedList(head);
    printf("Modified Linked List:\n");
    printList(newHead);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    while (newHead != NULL)
    {
        struct Node *temp = newHead;
        newHead = newHead->next;
        free(temp);
    }
    return 0;
}
