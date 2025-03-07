// WAP to print odd positioned elements and even positioned elements of an array separately.

#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    return temp;
}

void function(struct node *head,int size){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int array[size];
    for(int i=0;i<size;i++){
        array[i]=temp->data;
        temp=temp->next;
    }
    printf("odd ");
    for(int i=0;i<size;i++){
        // if(i%2==0){
        //     printf("%d",array[i]);
        // }
        printf("%d",array[i]);
    }
}

void display(struct node *head){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}

void main(){
    struct node *head=NULL;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    int size=6,val;
    for (int i=0;i<size;i++){
        // printf("%d",i);
        printf("Enter data: ");
        scanf("%d",&val);
        temp->data=val;
        temp->next=createNode();
    }
    head=temp;
    display(head);
    function(head,size);
}