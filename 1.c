#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for iterative in-order traversal
void iterativeInOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function for iterative post-order traversal
void iterativePostOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* temp = stack1[top1--];
        stack2[++top2] = temp;

        if (temp->left != NULL)
            stack1[++top1] = temp->left;
        if (temp->right != NULL)
            stack1[++top1] = temp->right;
    }

    while (top2 != -1) {
        struct Node* temp = stack2[top2--];
        printf("%d ", temp->data);
    }
}

// Function for iterative pre-order traversal
void iterativePreOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* temp = stack[top--];
        printf("%d ", temp->data);

        if (temp->right != NULL)
            stack[++top] = temp->right;
        if (temp->left != NULL)
            stack[++top] = temp->left;
    }
}

// Function to print the parent of a given element
void printParent(struct Node* root, int element) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* temp = stack[top--];

        if ((temp->left != NULL && temp->left->data == element) || (temp->right != NULL && temp->right->data == element)) {
            printf("Parent of %d is %d\n", element, temp->data);
            return;
        }

        if (temp->right != NULL)
            stack[++top] = temp->right;
        if (temp->left != NULL)
            stack[++top] = temp->left;
    }

    printf("Element not found in the tree!\n");
}

// Function to print the depth of the tree
int getDepth(struct Node* root) {
    if (root == NULL)
        return 0;

    int depth = 0;
    struct Node* queue[100];
    int front = -1;
    int rear = -1;

    queue[++rear] = root;

    while (front != rear) {
        int size = rear - front;

        while (size--) {
            struct Node* temp = queue[++front];

            if (temp->left != NULL)
                queue[++rear] = temp->left;
            if (temp->right != NULL)
                queue[++rear] = temp->right;
        }

        depth++;
    }

    return depth;
}

// Function to print the ancestors of a given element
void printAncestors(struct Node* root, int element) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* temp = stack[top--];

        if (temp->data == element) {
            printf("Ancestors of %d are: ", element);
            while (top != -1) {
                printf("%d ", stack[top--]->data);
            }
            printf("\n");
            return;
        }

        if (temp->right != NULL)
            stack[++top] = temp->right;
        if (temp->left != NULL)
            stack[++top] = temp->left;
    }

    printf("Element not found in the tree!\n");
}

// Function to count the number of leaf nodes in a binary tree
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top != -1) {
        struct Node* temp = stack[top--];

        if (temp->left == NULL && temp->right == NULL)
            count++;

        if (temp->right != NULL)
            stack[++top] = temp->right;
        if (temp->left != NULL)
            stack[++top] = temp->left;
    }

    return count;
}

int main() {
    // Create a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform operations on the binary tree
    printf("In-order traversal: ");
    iterativeInOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    iterativePostOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    iterativePreOrder(root);
    printf("\n");

    int element = 5;
    printParent(root, element);

    int depth = getDepth(root);
    printf("Depth of the tree: %d\n", depth);

    element = 7;
    printAncestors(root, element);

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}
