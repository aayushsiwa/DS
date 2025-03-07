#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation error");
        return ;
    }
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* insertNode(struct node* root,int data){
    if(root==NULL){
        root=createNode(data);
    }else{
        if(data<=root->data){
            root->left=insertNode(root->left,data);
        }else{
            root->right=insertNode(root->right,data);
        }

    }
    return root;
}

void inorderTraversal(struct node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

int main(){
    struct node* root=NULL;
    root=insertNode(root,50);
    insertNode(root,30);
    insertNode(root,70);
    insertNode(root,40);
    insertNode(root,50);
    insertNode(root,90);
    insertNode(root,100);
    insertNode(root,20);
    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}