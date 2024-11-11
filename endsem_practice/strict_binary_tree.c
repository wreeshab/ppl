#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a tree is strictly binary
bool isStrictlyBinary(struct Node* root) {
    if(root==NULL){
        return true;
    }
    if((root->left && !root->right) || (root->right && !root->left)) return false;

    return isStrictlyBinary(root->left) && isStrictlyBinary(root->right);
}

int main() {
    // Creating a test tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Check if the tree is strictly binary
    if (isStrictlyBinary(root)) {
        printf("The tree is strictly binary.\n");
    } else {
        printf("The tree is not strictly binary.\n");
    }

    return 0;
}
