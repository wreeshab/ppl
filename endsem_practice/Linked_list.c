#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void printList(struct Node* head){
    if(head == NULL) return;
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}

void insertAfterKthPosition(struct Node* head, int data, int k){ // inserts after kth element, not kth index.
    struct Node* temp = head;
    for(int i = 1; i<k; i++){
        temp = temp->next;
    }
    struct Node* next = temp->next;
    temp->next = createNode(data);
    temp->next->next = next;
}
void deleteAfterKthPosition(struct Node* head, int k){
    struct Node* temp = head;
    for(int i = 1; i<k; i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

int main (){
    const int n = 5;
    int array[5] = {1,3,5,2,6};
    struct Node* head = createNode(0);
    struct Node* temp = head;
    for (int i = 0; i<n; i++){
        temp->next = createNode(array[i]);
        temp = temp->next;
    }
    printList(head);

    insertAfterKthPosition(head, 23, 2);
    printList(head);
    deleteAfterKthPosition(head, 4);
    printList(head);
}

