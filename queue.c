// wap to 

#include<stdio.h>
#include "bootstrap.c"

int queue[5],n=5,front=-1,rear=-1;

void insert(int item){
    if(rear==n-1){
        printf("Queue is full\n");
        return;
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=item;
}

void delete(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}

void print(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void main(){
    printf("Enter the number of elements to be inserted\n");
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int item;
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        insert(item);
    }
    print();
    delete();
    delete();
    delete();
    print();
}