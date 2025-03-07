// WAP to create a menu driven program to implement circular queue operation such as Enqueue, Dequeue, IsEmpty, IsFull using array.
#include<stdio.h>
#include<stdlib.h>

int queue[10],front=-1,rear=-1,size=sizeof(queue)/sizeof(queue[0]);

void enqueue(int data){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=data;
    }
    else if((rear+1)%size==front){
        printf("Queue is full\n");
    }
    else{
        rear=(rear+1)%size;
        queue[rear]=data;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        printf("Deleted element is %d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Deleted element is %d\n",queue[front]);
        front=(front+1)%size;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%size;
        }
        printf("%d\n",queue[rear]);
    }
}


void main(){
    int choice,data;
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}