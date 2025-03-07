// perform following operations menu driven using functions on the single linked list:
//  search an element in the list
//  sort the list in ascending order
//  reverse the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createNode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insertAtEnd(struct node **head, int val)
{
    struct node *newnode = createNode(val);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
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

void search(struct node **head, int val)
{
    struct node *temp = *head;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}

void searchIn()
{
    printf("Enter element to search- ");
    int val;
    scanf("%d", &val);
    search(&head, val);
}

void sort(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        struct node *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->data > temp2->data)
            {
                int t = temp->data;
                temp->data = temp2->data;
                temp2->data = t;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    printf("Sorted list is:-\n");
}

void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("Reversed list is:-\n");
}

int main()
{
    printf("Given List is:-\n");
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 0);
    insertAtEnd(&head, 5);
    print(&head);
    printf("\n");
    while (1)
    {
        printf("1. Search an element in the list\n");
        printf("2. Sort the list in ascending order\n");
        printf("3. Reverse the list\n");
        printf("4. Exit\n");
        printf("Enter choice- ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            searchIn();
            break;
        case 2:
            sort(&head);
            print(&head);
            break;
        case 3:
            reverse(&head);
            print(&head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}