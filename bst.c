// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int searchNode(Node *root, int data) {
    if (root == NULL) {
        return 0;
    } else if (root->data == data) {
        return 1;
    } else if (data <= root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

int findMin(Node *root) {
    if (root == NULL) {
        printf("Error: Tree is empty\n");
        return -1;
    } else if (root->right == NULL) {
        return root->data;
    } else {
        return findMin(root->left);
    }
}

int findMax(Node *root) {
    if (root == NULL) {
        printf("Error: Tree is empty\n");
        return -1;
    } else if (root->left == NULL) {
        return root->data;
    } else {
        return findMax(root->right);
    }
}

int findHeight(Node *root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

void preOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}


void print(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
}

void leftMax(Node *root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        printf("%d ", root->left->data);
    }
    leftMax(root->left);
    leftMax(root->right);
}

int main() {
    Node *root = NULL;
    // 50 ,10, 25, 11, 16, 70, 40, 35, 55, 110
    root = insertNode(root, 50);
    root = insertNode(root, 10);
    root = insertNode(root, 25);
    root = insertNode(root, 11);
    root = insertNode(root, 16);
    root = insertNode(root, 70);
    root = insertNode(root, 40);
    root = insertNode(root, 35);
    root = insertNode(root, 55);
    root = insertNode(root, 110);

    int number;
    printf("Enter number to be searched: ");
    scanf("%d", &number);
    if (searchNode(root, number) == 1) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    printf("Min: %d\n", findMin(root));
    printf("Max: %d\n", findMax(root));
    printf("Height: %d\n", findHeight(root));

    printf("PreOrder: ");
    preOrder(root);
    printf("\n");

    printf("InOrder: ");
    inOrder(root);
    printf("\n");

    printf("PostOrder: ");
    postOrder(root);
    printf("\n");

    print(root);
    printf("\n");
    leftMax(root);

    return 0;
}