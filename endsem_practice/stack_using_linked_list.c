#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
}; // Missing semicolon added here

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* top = NULL;

void push(int data) {
    struct Node* temp = createNode(data);
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1; // Sentinel value for underflow
    }
    struct Node* toDelete = top;
    top = top->next;
    int data = toDelete->data;
    free(toDelete);
    return data;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1; // Sentinel value for empty stack
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

void printStack() {
    struct Node* current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    
    printStack();
    
    printf("Popped: %d\n", pop());
    printStack();

    printf("Top element is %d\n", peek());

    return 0;
}
