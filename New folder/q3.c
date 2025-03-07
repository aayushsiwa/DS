// wap removeDuplicates() function that takes a list and deletes any duplicate
// nodes from the list. The list is not sorted. 
// For example if the linked list is 12->11->12->21->;41->;43->;21 then
// removeDuplicates() should convert the list to 12->;11->;21->;41->;43.

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

void removeDuplicates(struct Node *head)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;
    while (temp != NULL)
    {
        prev = temp;
        next = temp->next;
        while (next != NULL)
        {
            if (next->data == temp->data)
            {
                prev->next = next->next;
                free(next);
                next = prev->next;
            }
            else
            {
                prev = next;
                next = next->next;
            }
        }
        temp = temp->next;
    }
}

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
    print(head);
    removeDuplicates(head);
    print(head);
    free(head);
}