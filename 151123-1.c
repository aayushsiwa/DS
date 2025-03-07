// WAP to create a bst of n elements using linked list and perform the following operations:
// a) Preorder Traversal
// b) Postorder Traversal
// c) Inorder Traversal
// d) Search
// e) Exit
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *root=NULL;

struct node *createNode(int data){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node *insert(struct node *root, int data){
    if(root==NULL){
        root=createNode(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
}

void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

struct node *search(struct node *root, int data){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==data){
        return root;
    }
    else if(data<=root->data){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
}

int main(){
    int n,data,choice;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the data: ");
    scanf("%d",&data);
    root=insert(root,data);
    for(int i=1;i<n;i++){
        printf("Enter the data: ");
        scanf("%d",&data);
        insert(root,data);
    }
    printf("1. Preorder Traversal\n"); 
    printf("2. Postorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Search\n");
    printf("5. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 2:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the data to be searched: ");
                scanf("%d",&data);
                if(search(root,data)!=NULL){
                    printf("Data found\n");
                }
                else{
                    printf("Data not found\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=5);
    return 0;
}