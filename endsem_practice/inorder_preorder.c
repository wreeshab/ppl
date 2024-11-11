//given inorder and  preorder, make the postorder of the the given binary tree.
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


int linearSearch(int arr[], int start, int end, int k ){
    for(int i = start;i<= end;i++){
        if(arr[i] == k) return i;
    }
    return -1;
}

void printPostOrder(int inorder[], int preorder[],int inStart, int inEnd, int *preIndex){
    if(inStart > inEnd) return;

    int root = preorder[*preIndex];
    (*preIndex)++;

    int inIndex = linearSearch(inorder,inStart, inEnd, root );
    printPostOrder(inorder, preorder, inStart, inIndex-1, preIndex);
    printPostOrder(inorder, preorder, inIndex +1, inEnd, preIndex);

    printf("%d ", root);

}

int main() {
      int inorder[] = {4, 2, 5, 1, 6, 3};
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    int preIndex = 0;
    printf("Postorder traversal: ");
    printPostOrder(inorder, preorder, 0, n - 1, &preIndex);
    printf("\n");

    return 0;
}
