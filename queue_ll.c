// wap to implement queue using linked list
// insert at end, delete from beginning.

#include<stdio.h>
#include "bootstrap.c"

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;

void insert(int val){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void delete(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
}

void print(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node *temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void main(){
    printf("Enter choice:-");
    printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\n");
    int choice;
    scanf("%d",&choice);
    while(choice!=4){
        switch(choice){
            case 1:{
                printf("Enter the item to be inserted\n");
                int item;
                scanf("%d",&item);
                insert(item);
                break;
            }
            case 2:{
                delete();
                break;
            }
            case 3:{
                print();
                break;
            }
            default:{
                printf("Invalid choice\n");
                break;
            }
        }
        printf("Enter choice:-");
        printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        scanf("%d",&choice);
    }
}