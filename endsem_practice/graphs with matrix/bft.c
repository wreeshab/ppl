#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;
int distance[MAX];

void enqueue(int data)
{
    if (rear == -1)
    {
        front++;
    }
    rear++;
    queue[rear] = data;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    front++;
    if (front > rear)
    { // Reset the queue when empty
        front = rear = -1;
    }
    return data;
}

void BFT(int startVertex, int vertices)
{
    visited[startVertex] = 1;
    enqueue(startVertex);

    printf("Order of vertices traversed in BFT: ");
    while (front != -1)
    {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
                distance[i] = distance[currentVertex] + 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int vertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (enter 0 or 1 for each entry):\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Initialize the visited array to 0
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    // Perform Breadth-First Traversal
    BFT(startVertex, vertices);
    for(int i=0;i<vertices;i++){
        printf("%d ", distance[i]);
    }

    return 0;
}
