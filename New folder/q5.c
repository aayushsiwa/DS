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
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

int detectAndRemoveLoop(struct Node *head)
{
    struct Node *temp1 = head;
    struct Node *temp2 = head;
    struct Node *prev = NULL;

    while (temp1 && temp2 && temp2->next)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;

        if (temp1 == temp2)
        {
            temp1 = head;
            while (temp1 != temp2)
            {
                prev = temp2;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            prev->next = NULL;
            return 1;
        }
    }

    return 0;
}

void printList(struct Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    // Create a loop for testing (1 -> 2 -> 3 -> 4 -> 5 -> 3)
    head->next->next->next->next->next = head->next->next;

    int loopDetected = detectAndRemoveLoop(head);

    if (loopDetected)
    {
        printf("Loop detected and removed.\n");
    }
    else
    {
        printf("No loop detected.\n");
    }

    printf("Linked List after removing the loop:\n");
    printList(head);

    while (head)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
