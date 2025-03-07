
#include <stdio.h>
#include "bootstrap.c"

// left->front
// right->rear

int left = -1;
int right = -1;
int max = 10;
int dequeue[10];

void insert_right()
{
    int item;
    if ((left == 0 && right == max - 1) || (left == right + 1))
        printf("Queue Overflow\n");
    else
    {
        if (left == -1)
            left = right = 0;
        else if (right == max - 1)
            right = 0;
        else
            right = right + 1;
        printf("Input the element for adding in queue: ");
        scanf("%d", &item);
        dequeue[right] = item;
    }
}

void insert_left()
{
    int item;
    if ((left == 0 && right == max - 1) || (left == right + 1))
        printf("Queue Overflow\n");
    else
    {
        if (left == -1)
        {
            left = 0;
            right = 0;
        }
        else if (left == 0)
            left = max - 1;
        else
            left = left - 1;
        printf("Input the element for adding in queue: ");
        scanf("%d", &item);
        dequeue[left] = item;
    }
}

void delete_left()
{
    if (left == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is: %d\n", dequeue[left]);
    if (left == right)
    {
        left = right = -1;
    }
    else
    {
        if (left == max - 1)
            left = 0;
        else
            left = left + 1;
    }
}

void delete_right()
{
    if (left == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is: %d\n", dequeue[right]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else
    {
        if (right == 0)
            right = max - 1;
        else
            right = right - 1;
    }
}

void display()
{
    int front = left, rear = right;
    if (left == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front <= rear)
    {
        while (front <= rear)
        {
            printf("%d ", dequeue[front]);
            front++;
        }
    }
    else
    {
        while (front <= max - 1)
        {
            printf("%d ", dequeue[front]);
            front++;
        }
        front = 0;
        while (front <= rear)
        {
            printf("%d ", dequeue[front]);
            front++;
        }
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert at right\n");
        printf("2.Insert at left\n");
        printf("3.Delete from left\n");
        printf("4.Delete from right\n");
        printf("5.Display\n");
        printf("6.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            delete_right();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}