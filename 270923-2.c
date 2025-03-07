//write a program to create a double linked list and perform the follwing menu based operations on it:
// insert an element at specific position
// delete an element from specific position
// traverse the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insert(struct node **head, int data, int pos)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    if (pos == 0)
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    struct node *temp = *head;
    int i = 0;
    while (i < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL)
    {
        temp->next = new_node;
        new_node->prev = temp;
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
}

void delete (struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 0)
    {
        struct node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }

    struct node *temp = *head;
    int i = 0;
    while (i < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void traverse(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("->NULL\n");
}

int main()
{
    struct node *head = NULL;
    int choice, data, pos;
    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data and position: ");
            scanf("%d%d", &data, &pos);
            insert(&head, data, pos);
            break;
        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete (&head, pos);
            traverse(head);
            break;
        case 3:
            traverse(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
