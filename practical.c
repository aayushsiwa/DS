// WAP to print odd positioned elements and even positioned elements of an array separately.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void print(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void print_odd_even(struct node *head){
    struct node *temp = head;
    int count = 1;
    printf("Even positioned elements: ");
    while(temp != NULL){
        if(count % 2 == 0){
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
    printf("\n");
    temp = head;
    count = 1;
    printf("Odd positioned elements: ");
    while(temp != NULL){
        if(count % 2 != 0){
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
}

int main(){
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;
    struct node *sixth = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = NULL;

    print(head);
    printf("\n");
    print_odd_even(head);
    return 0;
}

