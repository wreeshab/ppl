#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int vertices;
int isDirected;
int distance[MAX];

// Queue for BFS
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = data;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front++];
    if (front > rear) {
        front = rear = -1;
    }
    return data;
}

void bft(int startVertex) {
    // Initialize visited and distance arrays
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        distance[i] = -1;
    }

    // Start BFS from the startVertex
    enqueue(startVertex);
    visited[startVertex] = 1;
    distance[startVertex] = 0;

    while (front != -1) {
        int current = dequeue();
        printf("Visited %d with distance %d\n", current, distance[current]);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
                distance[i] = distance[current] + 1;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("1 for directed and 0 for undirected: ");
    scanf("%d", &isDirected);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // If the graph is undirected, make the adjacency matrix symmetric
    if (!isDirected) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    adjMatrix[j][i] = 1;
                }
            }
        }
    }

    // Perform BFS traversal from vertex 0 as an example
    printf("BFS traversal starting from vertex 0:\n");
    bft(0);

    return 0;
}
