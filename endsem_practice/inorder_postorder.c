#include <stdio.h>
#include <stdlib.h>

//rule of thumb -> inorder, preorder given -> left and then right 
// inorder and postorder given -> right and then left.

// Structure to represent a node in the binary tree
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

// Function to find the index of an element in the inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to build the tree from inorder and postorder arrays
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
   if(inStart > inEnd) return NULL;

   int rootData = postorder[*postIndex];
   (*postIndex)--;

   struct Node* root = createNode(rootData);
   if(inStart == inEnd ) return root;

    int inIndex = search(inorder, inStart, inEnd, rootData);

    root->right = buildTree(inorder, postorder, inIndex+1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex-1, postIndex);
    
    

    return root;

}

// Function to print the inorder traversal of the tree (for verification)
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    // Example inorder and postorder traversals
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};

    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = n - 1;

    // Build the tree
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    // Verify by printing the inorder traversal of the constructed tree
    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
