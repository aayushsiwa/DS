// wap to create a single linked list, delete a node from beginning, end, any position

#include <stdio.h>
#include "bootstrap.c"

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

void deleteEnd(struct node **head, int val)
{
    
}

void main()
{

    // int* arr=;
    // free(arr);
}