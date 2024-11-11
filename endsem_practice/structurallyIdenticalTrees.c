#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node* ) malloc(sizeof(struct Node));
    newNode->data  = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
bool isIdentical(struct Node* root1, struct Node* root2){
    if(!root1 && !root2) return true;

    if(!root1 || !root2) return false;

    return (root1->data == root2->data) && isIdentical(root1->left, root2->left) && isIdentical(root2->right, root1->right);
}

int main() {

    struct Node* root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(20);
    root1->left->left = createNode(3);
    root1->left->right = createNode(7);
    root1->right->left = createNode(15);
    root1->right->right = createNode(25);

    struct Node* root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(20);
    root2->left->left = createNode(3);
    root2->left->right = createNode(7);
    root2->right->left = createNode(15);
    root2->right->right = createNode(25);

     if (isIdentical(root1, root2)) {
        printf("The trees are identical.\n");
    } else {
        printf("The trees are not identical.\n");
    }

}
