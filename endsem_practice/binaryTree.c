#include<stdlib.h>
#include<stdio.h>

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
int totalNodes(struct Node* head){
    if(head ==NULL){
        return 0;
    }
    return 1+totalNodes(head->left) + totalNodes(head->right);
}
int sumOfElements(struct Node* head){
    if(head ==NULL){
        return 0;
    }
    return head->data+ sumOfElements(head->left) + sumOfElements(head->right);
}
int findHeight(struct Node* head){
    if(head == NULL){
        return 0;
    }
    return 1 + (findHeight(head->left) > findHeight(head->right)?findHeight(head->left):findHeight(head->right));
}
int maxi(struct Node* head){
    if(head==NULL){
        return 0;
    }
    int left = maxi(head->left);
    int right = maxi(head->right);
    int maximum = head->data;
    if (left > maximum) maximum = left;
    if (right > maximum) maximum = right;

    return maximum;
}
int main() {
    // Create a sample binary tree
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // Test totalNodes function
    printf("Total number of nodes: %d\n", totalNodes(root));

    // Test sumOfElements function
    printf("Sum of all elements: %d\n", sumOfElements(root));

    // Test findHeight function
    printf("Height of the tree: %d\n", findHeight(root));

    // Test maxi function
    printf("Maximum element in the tree: %d\n", maxi(root));

    return 0;
}
