//write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

void create(struct node **head, int n)
{
    struct node *temp = *head, *newNode;
    int coeff, exp;

    for (int i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient of node %d: ", i + 1);
        scanf("%d", &coeff);
        printf("Enter the exponent of node %d: ", i + 1);
        scanf("%d", &exp);
        newNode->coeff = coeff;
        newNode->exp = exp;
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
}

void display(struct node *head)
{
    struct node *temp = head;
    printf("The elements of the polynomial equation are: ");
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

void add(struct node *head1, struct node *head2, struct node **head3)
{
    struct node *temp1 = head1, *temp2 = head2, *temp3 = *head3, *newNode;
    while (temp1 != NULL && temp2 != NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (temp1->exp > temp2->exp)
        {
            newNode->coeff = temp1->coeff;
            newNode->exp = temp1->exp;
            newNode->next = NULL;
            temp1 = temp1->next;
        }
        else if (temp1->exp < temp2->exp)
        {
            newNode->coeff = temp2->coeff;
            newNode->exp = temp2->exp;
            newNode->next = NULL;
            temp2 = temp2->next;
        }
        else
        {
            newNode->coeff = temp1->coeff + temp2->coeff;
            newNode->exp = temp1->exp;
            newNode->next = NULL;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (*head3 == NULL)
        {
            *head3 = newNode;
            temp3 = *head3;
        }
        else
        {
            temp3->next = newNode;
            temp3 = temp3->next;
        }
    }
    while (temp1 != NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coeff = temp1->coeff;
        newNode->exp = temp1->exp;
        newNode->next = NULL;
        temp1 = temp1->next;
        temp3->next = newNode;
        temp3 = temp3->next;
    }
    while (temp2 != NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->coeff = temp2->coeff;
        newNode->exp = temp2->exp;
        newNode->next = NULL;
        temp2 = temp2->next;
        temp3->next = newNode;
        temp3 = temp3->next;
    }
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    int n1, n2;
    printf("Enter the number of nodes in the first polynomial equation: ");
    scanf("%d", &n1);
    create(&head1, n1);
    printf("Enter the number of nodes in the second polynomial equation: ");
    scanf("%d", &n2);
    create(&head2, n2);
    display(head1);
    display(head2);
    add(head1, head2, &head3);
    display(head3);
    return 0;
}