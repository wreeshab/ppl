#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int vertices;
int isDirected;
int hasCycle = 0;
int finishTime[MAX];
int time = 0;

void dfs(int startVertex) {
    visited[startVertex] = 1;  // Mark as visiting
    printf("Visited %d\n", startVertex);

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[startVertex][i]) {  // There is an edge
            if (visited[i] == 0) {  // If not visited, visit it recursively
                dfs(i);
            } else if (visited[i] == 1) {  // If visiting, a cycle is detected
                hasCycle = 1;
            }
        }
    }
    visited[startVertex] = 2;  // Mark as fully explored
    finishTime[startVertex] = ++time;  // Set the finishing time
}

void dfsWrapper() {
    // Initialize visited and finishing time arrays
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        finishTime[i] = -1;
    }
    time = 0;
    hasCycle = 0;

    // Perform DFS for each unvisited vertex
    printf("DFS Traversal Order:\n");
    for (int i = 0; i < vertices; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter 1 for directed and 0 for undirected graph: ");
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

    // Perform DFS traversal
    dfsWrapper();

    // Print finishing times
    printf("\nFinishing Times:\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: %d\n", i, finishTime[i]);
    }

    // Check if a cycle exists
    if (hasCycle) {
        printf("\nThe graph has a cycle.\n");
    } else {
        printf("\nThe graph does not have a cycle.\n");
    }

    return 0;
}
