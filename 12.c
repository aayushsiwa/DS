// C program to implement optimized delete in BST.
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *left, *right;
};

// A utility function to create a new BST node
struct Node* newNode(int item)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in
* BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct Node* deleteNode(struct Node* root, int k)
{
	// Base case
	if (root == NULL)
		return root;

	// Recursive calls for ancestors of
	// node to be deleted
	if (root->key > k) {
		root->left = deleteNode(root->left, k);
		return root;
	}
	else if (root->key < k) {
		root->right = deleteNode(root->right, k);
		return root;
	}

	// We reach here when root is the node
	// to be deleted.

	// If one of the children is empty
	if (root->left == NULL) {
		struct Node* temp = root->right;
		free(root);
		return temp;
	}
	else if (root->right == NULL) {
		struct Node* temp = root->left;
		free(root);
		return temp;
	}

	// If both children exist
	else {

		struct Node* succParent = root;

		// Find successor
		struct Node* succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		// Delete successor. Since successor
		// is always left child of its parent
		// we can safely make successor's right
		// right child as left of its parent.
		// If there is no succ, then assign
		// succ->right to succParent->right
		if (succParent != root)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;

		// Copy Successor Data to root
		root->key = succ->key;

		// Delete Successor and return root
		free(succ);
		return root;
	}
}

// Driver Code
int main()
{
	struct Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 9);
	inorder(root);
	printf("\n");
	root=deleteNode(root,3);
	inorder(root);
}
