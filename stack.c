// wap to

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node *createNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    return newNode;
}

int push(struct node **top, int val)
{
    struct node *newNode = createNode();
    newNode->data = val;
    if (*top == NULL)
    {
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        *top = newNode;
    }
}

int pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("\nEMPTY STACK");
        return -1;
    }
    else
    {
        // struct node *temp = *top;
        // int temp_data = (*top)->data; // to store data of top node
        top = (*top)->next;
        // free(temp); // deleting the node
        // return temp_data;
    }
}

void display(struct node *top)
{
    struct node* current = top;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void peek(struct node *top){
    if(top==NULL){
        printf("\nEMPTY STACK");
    }
    else{
        printf("%d\n",top->data);
    }
}

void main()
{
    struct node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);
    peek(top);
    pop(&top);
    display(top);
    peek(top);
    // int* arr=;
    // free(arr);
}