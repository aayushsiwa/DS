#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (root->data <= data)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        root->left = insertNode(root->left, data);
    }
    return root;
}

int searchNode(struct Node *root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == val)
    {
        return -1;
    }
    else if (root->data <= val)
    {
        return searchNode(root->right, val);
    }
    else
    {
        return searchNode(root->left, val);
    }
}

int findMin(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return findMin(root->left);
    }
}

int findMax(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return findMax(root->right);
    }
}

void printTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    printTree(root->right);
    printTree(root->left);
}

void postorder(struct Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main()
{
    struct Node *root = NULL;
    // root = insertNode(root, 50);
    // root = insertNode(root, 10);
    // root = insertNode(root, 25);
    // root = insertNode(root, 11);
    // root = insertNode(root, 16);
    // root = insertNode(root, 70);
    // root = insertNode(root, 40);
    // root = insertNode(root, 35);
    // root = insertNode(root, 55);
    // root = insertNode(root, 110);
    root = createNode(50);
    root->left=createNode(10);
    root->left->right=createNode(11);
    root->right=createNode(25);
    root->right->left=createNode(16);
    root->right->right=createNode(70);
    root->right->right->right=createNode(110);
    root->right->right->left=createNode(40);
    root->right->right->left->right=createNode(55);
    root->right->right->left->left=createNode(35);

    printTree(root);
    printf("\n");
    printf("%d", findMin(root));
    printf("\n");
    printf("%d", findMax(root));
    printf("\nPOST ");
    postorder(root);
}