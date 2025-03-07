// wap to perform following operations on a stack using array
// push
// pop
// display
// isFull
// isEmpty

#include <stdio.h>
#include "bootstrap.c"

int isFull(int stack[], int *top, int size)
{
    if (*top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        for (int i = *top; i >= 0; i--)
        {
            printf("%d->", stack[i]);
        }
    }
    printf("Bottom\n");
}

void push(int stack[], int *top, int size)
{
    int element;
    printf("Enter the element to be pushed: ");
    scanf("%d", &element);
    if (isFull(stack, top, size))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        // *top++;
        stack[++(*top)] = element;
        // printf("%d",*top);
    }
}

void pop(int stack[], int *top, int size)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped element is %d\n", stack[(*top)--]);
    }
}

void main()
{
    int *stack = (int *)malloc(sizeof(int));
    // int stack[10];
    int top = -1;
    int choice;
    int size;
    int element;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. isFull\n5. isEmpty\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(stack, &top, size);
            // printf("%d\n",isFull(stack, &top, size));
            break;

        case 2:
            pop(stack, &top, size);
            break;

        case 3:
            display(stack, &top);
            break;

        case 4:
            // push(stack, top, size);
            break;
        default:
            break;
        }
    }
}