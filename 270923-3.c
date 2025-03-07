//write a program to create a circular linked list and display the elements of the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **head, int n)
{
    struct node *temp = *head, *newNode;
    int data;

    for (int i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d: ", i + 1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            temp = *head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    temp->next = *head;
}

void display(struct node *head)
{
    struct node *temp = head;
    printf("The elements of the circular linked list are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    create(&head, n);
    display(head);
    return 0;
}

