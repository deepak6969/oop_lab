#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Function to print the binary tree in inorder traversal
void printInorder(struct Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    printf("Inorder traversal of the binary tree: ");
    printInorder(root);

    return 0;
}

