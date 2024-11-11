#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element to the queue (enqueue)
void enqueue(int data) {
    struct Node* temp = createNode(data);
    if (rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return -1; // Indicates an error
    }
    struct Node* toDelete = front;
    front = front->next;
    int data = toDelete->data;
    free(toDelete);

    // If the queue is now empty, set rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }

    return data;
}

// Function to display the queue
void displayQueue() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    displayQueue();

    printf("Dequeued: %d\n", dequeue());
    displayQueue();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    // Attempt to dequeue from an empty queue
    printf("Dequeued: %d\n", dequeue());
    displayQueue();

    return 0;
}
