// WAP to create a menu driven program to implement linear queue operation such as Enqueue, Dequeue, IsEmpty, IsFull using array.
#include<stdio.h>
#include<stdlib.h>

int front=-1,rear=-1,queue[10],n=sizeof(queue)/sizeof(queue[0]);

void enqueue(int queue[], int data){
    if(rear==n){
        printf("Queue is full");
    }
    else{
        queue[rear]=data;
        rear++;
    }
}

void dequeue(int queue[]){
    if(front==rear){
        printf("Queue is empty");
    }
    else{
        front++;
    }
}

void isEmpty(int queue[]){
    if(front==rear){
        printf("\nTrue\n");
    }
    else{
        printf("\nFalse\n");
    }
}

void isFull(int queue[]){
    if(rear==n){
        printf("\nTrue\n");
    }
    else{
        printf("\nFalse\n");
    }
}

void traverse(int queue[]){
    if(front==rear){
        printf("Queue is empty");
    }
    else{
        for(int i=front;i<rear;i++){
            printf("%d ", queue[i]);
        }
    }
}


void main(){
    int data, choice;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Traverse\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                isEmpty(queue);
                break;
            case 4:
                isFull(queue);
                break;
            case 5:
                traverse(queue);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}