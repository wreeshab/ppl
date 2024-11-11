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

struct Node* insertNode(struct Node* root, int data){
    if(root == NULL) {
        return createNode(data);
    }
    if(root->data < data){
        root->right = insertNode(root->right, data);
    }else if(root->data > data){
        root->left = insertNode(root->left, data);
    }

    return root;
}

struct Node* findMini(struct Node* root){
    struct Node* temp = root;
    while(temp && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

struct Node* deleteNode(struct Node* root, int data){
     if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else{
        if(root->left == NULL){
            struct Node* right  = root-> right;
            free(root);
            return right;
        }else if(root->right ==NULL){
            struct Node* left = root->left;
            free(root);
            return left;
        }

        struct Node* temp = findMini(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("Deleting 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    printf("Deleting 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}