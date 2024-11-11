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

struct Node* ReverseWithoutRecursion(struct Node* head){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node* reverseWithRecursion(struct Node* head){
    if(head== NULL || head->next == NULL) return head;

    struct Node* secondEle = head->next;
    head->next = NULL;
    struct Node* returned = reverseWithRecursion(secondEle);
    secondEle->next = head;
    return returned;

}

int main() {
    int array[] = {1, 3, 5, 2, 6};
    int n = sizeof(array) / sizeof(array[0]);

    // Initialize the linked list
    struct Node* head = createNode(array[0]);
    struct Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = createNode(array[i]);
        temp = temp->next;
    }

    printf("Original list: ");
    printList(head);

    // Reverse the linked list
    head = reverseWithRecursion(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}