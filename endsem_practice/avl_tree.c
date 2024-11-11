#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->height = 1;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node* root) {
    return (root == NULL) ? 0 : root->height;
}

int getBalance(struct Node* root) {
    return (root == NULL) ? 0 : getHeight(root->left) - getHeight(root->right);
}

struct Node* rotateRight(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

struct Node* rotateLeft(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalance(root);

    if (bf > 1 && data < root->left->data) {
        return rotateRight(root);
    }
    if (bf < -1 && data > root->right->data) {
        return rotateLeft(root);
    }
    if (bf > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

struct Node* findMini(struct Node* root) {
    struct Node* temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* right = root->right;
            free(root);
            return right;
        } else if (root->right == NULL) {
            struct Node* left = root->left;
            free(root);
            return left;
        }

        struct Node* temp = findMini(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalance(root);

    if (bf > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }
    if (bf > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }
    if (bf < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
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

    printf("Inorder traversal of the AVL tree: ");
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
