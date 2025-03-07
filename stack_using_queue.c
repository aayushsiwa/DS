#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}

void push(struct Stack* stack, int item) {
    if (isEmpty(stack->q1)) {
        enqueue(stack->q1, item);
        while (!isEmpty(stack->q2)) {
            enqueue(stack->q1, dequeue(stack->q2));
        }
    } else {
        enqueue(stack->q2, item);
        while (!isEmpty(stack->q1)) {
            enqueue(stack->q2, dequeue(stack->q1));
        }
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack->q1) && isEmpty(stack->q2)) {
        return -1;
    }
    if (!isEmpty(stack->q1)) {
        return dequeue(stack->q1);
    } else {
        return dequeue(stack->q2);
    }
}

int top(struct Stack* stack) {
    if (isEmpty(stack->q1) && isEmpty(stack->q2)) {
        return -1;
    }
    if (!isEmpty(stack->q1)) {
        return stack->q1->array[stack->q1->front];
    } else {
        return stack->q2->array[stack->q2->front];
    }
}

void display(struct Stack* stack){
    if (isEmpty(stack->q1) && isEmpty(stack->q2)) {
        printf("Stack is empty\n");
        return;
    }
    if (!isEmpty(stack->q1)) {
        for(int i=stack->q1->front;i<=stack->q1->rear;i++){
            printf("%d ",stack->q1->array[i]);
        }
        printf("\n");
    } else {
        for(int i=stack->q2->front;i<=stack->q2->rear;i++){
            printf("%d ",stack->q2->array[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack* stack = createStack();
    // printf("%d\n", top(stack));
    // push(stack, 1);
    // printf("%d\n", top(stack));
    // push(stack, 2);
    // printf("%d\n", top(stack));
    // push(stack, 3);
    // printf("%d\n", top(stack));

    // printf("current size: %d\n", stack->q1->size + stack->q2->size);
    // printf("%d\n", top(stack));
    // pop(stack);
    // printf("%d\n", top(stack));
    // pop(stack);
    // printf("%d\n", top(stack));

    // printf("current size: %d\n", stack->q1->size + stack->q2->size);
    // return 0;
    int choice=0;
    int item;
    while(choice!=5){
        printf("Enter your choice\n");
        printf("1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the item to be pushed\n");
                scanf("%d",&item);
                push(stack,item);
                break;
            case 2:
                item=pop(stack);
                if(item==-1){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Popped item is %d\n",item);
                }
                break;
            case 3:
                item=top(stack);
                if(item==-1){
                    printf("Stack is empty\n");
                }
                else{
                    printf("Top item is %d\n",item);
                }
                break;
            case 4:
                display(stack);
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
