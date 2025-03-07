#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head=NULL;

struct Node *createNode(int val){
    struct Node *temp=head;
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertAtEnd(int val){
    struct Node *newNode=createNode(val);
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        temp->prev=temp;
    }
}

void print(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%n");
}

void main(){
    struct Node *first=createNode(1);
    struct Node *A=createNode(20);
    struct Node *B=createNode(30);
    struct Node *C=createNode(40);
    struct Node *last=createNode(2);
    first->next=A;
    A->next=B;
    B->next=C;
    C->next=last;
    last->next=first;
    first->prev=last;
    A->prev=first;
    B->prev=A;
    C->prev=B;
    last->prev=C;
    head=first;
    print(head);
}



// Doubly
// struct Node
// {
//     int data;
//     struct Node *next;
//     struct Node *prev;
// };

// struct Node *head = NULL;

// struct Node *createNode(int val)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = val;
//     newNode->next = NULL;
//     newNode->prev = NULL;
//     return newNode;
// }

// void print(struct Node *head)
// {
//     struct Node *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// void print_rev(struct Node *prev){
//     struct Node *temp=prev;
//     while(temp!=NULL){
//         printf("%d ",temp->data);
//         temp=temp->prev;
//     }
//     printf("\n");
// }

// void insertAtEnd(int val)
// {
//     struct Node *newNode = createNode(val);
//     if(head==NULL){
//         head=newNode;
//     }
//     else{
//         struct Node *temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=newNode;
//         newNode->prev=temp;
//     }
    
// }

// void main()
// {
//     struct Node *first=createNode(1);
//     struct Node *second=createNode(2);
//     struct Node *third=createNode(3);
//     struct Node *fourth=createNode(4);
//     struct Node *last=createNode(5);
//     first->next=second;
//     second->next=third;
//     third->next=fourth;
//     fourth->next=last;
//     last->next=NULL;
//     first->prev=NULL;
//     second->prev=first;
//     third->prev=second;
//     fourth->prev=third;
//     last->prev=fourth;
//     head=first;
//     struct Node *prev=last;
//     print(head);
//     print_rev(prev);
// }

// wap to Merging refers to combining two sorted arrays
// into one sorted array. It involves 2 steps –
//  Sorting the arrays that are to be merged
//  Adding the sorted elements of both arrays to
// a new array in sorted order

// void print(int arr[], int n)
// {
//     int i;
//     printf("\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

// int sort(int arr[], int n)
// {
//     int i, j, temp;
//     for (i = 0; i < n; i++)
//     {
//         for (j = i; j < n - 1; j++)
//         {
//             if (arr[i] > arr[j + 1])
//             {
//                 temp = arr[i];
//                 arr[i] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     // print(arr, n);
// }

// void main()
// {
//     int arr1[] = {10, 2, 3, 4, 6, 5, 7, 8, 9, 1};
//     int arr2[] = {11, 12, 13, 14, 15, 16, 17, 20, 18, 19};
//     int n1 = sizeof(arr1) / sizeof(arr1[0]), n2 = sizeof(arr2) / sizeof(arr2[0]);
//     sort(arr1,n1);
//     sort(arr2,n2);
//     // print(arr1,n1);
//     // print(arr2,n2);
//     int arr3[n1 + n2], i, j;
//     for (i = 0; i < n1; i++)
//     {
//         arr3[i] = arr1[i];
//     }
//     for (j = 0; j < n2; j++)
//     {
//         arr3[i] = arr2[j];
//         i++;
//     }
//     print(arr3, n1 + n2);
// }