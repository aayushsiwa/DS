// binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void insertNode(struct Node *root,int data){
    struct Node *newNode=createNode(data);
    struct Node *temp=root;
    if(root==NULL){
        root=newNode;
        return;
    }
    if(data<temp->data){
        if(temp->left==NULL){
            temp->left=newNode;
            return;
        }else{
            insertNode(temp->left,data);
        }
    }
    else{
        if(temp->right==NULL){
            temp->right=newNode;
            return;
        }else{
            insertNode(temp->right,data);
        }
    }
}

void inorder(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        return;
    }
    inorder(temp->left);
    printf("%d->",temp->data);
    inorder(temp->right);
}

void preorder(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        return;
    }
    printf("%d->",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d->",temp->data);
}

struct Node *search(struct Node *root, int data){
    struct Node *temp=root;
    if(temp==NULL){
        return NULL;
    }
    else if(temp->data==data){
        printf("Found\n");
        return temp;
    }
    else if(data>temp->data){
        temp=temp->right;
        return search(temp,data);  
    }
    else if(data<temp->data){
        temp=temp->left;
        return search(temp,data);
    }
    else{
        return NULL;
    }
}

struct Node *min(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        return root;;
    }
    while(temp->left!=NULL){
        temp=temp->left;
    }
    printf("Minimum = %d\n",temp->data);
    return root;
}

void max(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        return;
    }
    while(temp->right!=NULL){
        temp=temp->right;
    }
    printf("Maximum = %d\n",temp->data);
}

struct Node *delete(struct Node *root,int data){
    struct Node *temp;
    if(root==NULL){
        return root;
    }
    
    if(data>root->data){
        // printf("%d",root->data);
        root->right=delete(root->right,data);
        return root;
    }
    else if(data<root->data){
        // printf("%d",root->data);
        root->left=delete(root->left,data);
        return root;
    }
    
    // Case :  If any one child exists
    if(root->left==NULL){
        temp=root->right;
        free(root);
        return temp;
    }
    else if(root->right==NULL){
        temp=root->left;
        free(root);
        return temp;
    }
    // Case : Both child exists
    // else{
    //     struct Node *succParent=root;

    //     struct Node *succ=root->right;

    //     while(succ->left!=NULL){
    //         succParent=succ;
    //         succ=succ->left;
    //     }

    //     if(succParent!=root){
    //         succParent->left=succ->right;
    //     }
    //     else{
    //         succParent->right=succ->right;
    //     }
    //     root->data=succ->data;

    //     free(succ);
    //     return root;
    // }
    else {
        temp=min(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
}

int countNodes(struct Node *root){
    struct Node *temp=root;
    int count=0;
    if(temp==NULL){
        return count;
    }
    else{
        count++;
        return count+countNodes(temp->left)+countNodes(temp->right);
    }
}

int height(struct Node *root){
    struct Node *temp=root;
    int leftHeight=0;
    int rightHeight=0;
    if(temp==NULL){
        return 0;
    }
    else{
        leftHeight=height(temp->left);
        rightHeight=height(temp->right);
        // if(leftHeight>rightHeight){
        //     return leftHeight+1;
        // }
        // else{
        //     return rightHeight+1;
        // }
        return fmax(leftHeight,rightHeight)+1;
        // return (leftHeight>rightHeight)?leftHeight+1:rightHeight+1;
    }
}

int sumOfNodes(struct Node *root){
    struct Node *temp=root;
    int sum=0;
    int leftSum=0;
    int rightSum=0;
    if(temp==NULL){
        return sum;
    }
    else{
        leftSum=sumOfNodes(temp->left);
        rightSum=sumOfNodes(temp->right);
        sum=temp->data+leftSum+rightSum;
        return sum;
    }
}

int isBalanced(struct Node *root){
    struct Node *temp=root;
    if(temp==NULL){
        return -1;
    }
    int lH=height(temp->left);
    int rH=height(temp->right);
    int balanceFactor=lH-rH;
    // printf("%d",balanceFactor);
    if(balanceFactor==-1 || balanceFactor==0 || balanceFactor==1){
        printf("Tree is balanced\n");
        return 0;
    }
    else{
        printf("Tree is not balanced\n");
        return 1;
    }
}

struct Node *leftRotation(struct Node *root){
    struct Node *temp=root->right;
    struct Node *temp2=temp->left;

    temp->left=root;
    root->right=temp2;

    return temp;
}

struct Node *rightRotation(struct Node *root){
    struct Node *temp=root->left;
    struct Node *temp2=temp->right;

    temp->right=root;
    root->left=temp2;

    return temp;
}

struct Node *avlInsert(struct Node *root,int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=avlInsert(root->left,data);
    }
    else if(data>root->data){
        root->right=avlInsert(root->right,data);
    }
    else{
        return root;
    }
    int balancefactor=height(root->left)-height(root->right);
    
    if(balancefactor>1 && data< root->left->data){
        return rightRotation(root);
    }
    if(balancefactor<-1 && data>root->right->data){
        return leftRotation(root);
    }
    if (balancefactor > 1 && data > root->left->data) 
    { 
        root->left =  leftRotation(root->left); 
        return rightRotation(root); 
    } 
    if (balancefactor < -1 && data < root->right->data) 
    { 
        root->right = rightRotation(root->right); 
        return leftRotation(root); 
    } 
    return root; 
}

// void main(){
//     struct Node *root=createNode(5);
//     insertNode(root,3);
//     insertNode(root,7);
//     insertNode(root,2);
//     insertNode(root,4);
//     insertNode(root,6); 
//     insertNode(root,8);
//     insertNode(root,9);
//     printf("%d\n",root->data);
//     inorder(root);
//     printf("NULL\n");
//     preorder(root);
//     printf("NULL\n");
//     postorder(root);
//     printf("NULL\n");
//     search(root,2);
//     min(root);
//     max(root);
//     delete(root,9);
//     delete(root,8);
//     insertNode(root,1);
//     insertNode(root,0);
//     inorder(root);
//     printf("NULL\n");
//     printf("Number of nodes = %d\n",countNodes(root));
//     printf("Sum of nodes = %d\n",sumOfNodes(root));
//     printf("Height of tree = %d\n",height(root));
//     isBalanced(root);
//     delete(root,1);
//     delete(root,0);
//     delete(root,6);
//     insertNode(root,8);
//     inorder(root);
//     printf("NULL\n");
//     isBalanced(root);
//     // avlInsert(root,9);
//     // insertNode(root,9);
//     // insertNode(root,11);
//     avlInsert(root,9);
//     avlInsert(root,11);
//     inorder(root);
//     isBalanced(root);
//     // inorder(root);
//     isBalanced(root);
// }


void main(){
    struct Node *root=createNode(23);
    int array[]={64, 48, 96, 101, 34, 55, 11, 22, 41,89, 71, 78, 61, 83, 94, 8, 27, 35, 1};
    for(int i=0;i<sizeof(array)/sizeof(int);i++){
        printf("%d\n",array[i]);
        insertNode(root,array[i]);
        inorder(root);
        printf("NULL\n");
    }
}
// 23,64, 48, 96, 101, 34, 55, 11, 22, 41,89, 71, 78, 61, 83, 94, 8, 27, 35, 1.