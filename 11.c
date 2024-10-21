#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// a. Check if the graph is complete
int isComplete(int G[MAX][MAX], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && G[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// a. Obtain degree (undirected) or indegree/outdegree (directed)
void getDegree(int G[MAX][MAX], int V, int node, int isDirected) {
    int inDegree = 0, outDegree = 0;

    for (int i = 0; i < V; i++) {
        if (G[i][node]) {
            inDegree++;
        }
        if (G[node][i]) {
            outDegree++;
        }
    }

    if (isDirected) {
        printf("Indegree of node %d: %d\n", node, inDegree);
        printf("Outdegree of node %d: %d\n", node, outDegree);
    } else {
        printf("Degree of node %d: %d\n", node, outDegree); // In undirected graphs, degree = outDegree.
    }
}

// a. Check if path exists between two vertices (BFS)
int pathExists(int G[MAX][MAX], int V, int start, int end) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        if (node == end) {
            return 1; // Path found
        }

        for (int i = 0; i < V; i++) {
            if (G[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    return 0;
}

// b. Breadth-First Traversal (BFT) and shortest distance from source
void BFT(int G[MAX][MAX], int V, int source) {
    int visited[MAX] = {0}, distance[MAX];
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        distance[i] = -1;
    }

    visited[source] = 1;
    distance[source] = 0;
    queue[rear++] = source;

    printf("BFS Traversal Order: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (G[node][i] && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[node] + 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\nShortest distances from source:\n");
    for (int i = 0; i < V; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }
}

// c. Depth-First Traversal (DFT) and cycle checking, finishing time
int time = 0;
void DFTUtil(int G[MAX][MAX], int V, int node, int visited[], int *hasCycle, int finishTime[]) {
    visited[node] = 1;
    printf("%d ", node);
    time++;

    for (int i = 0; i < V; i++) {
        if (G[node][i]) {
            if (!visited[i]) {
                DFTUtil(G, V, i, visited, hasCycle, finishTime);
            } else if (visited[i] == 1) {
                *hasCycle = 1;
            }
        }
    }

    visited[node] = 2;
    finishTime[node] = ++time;
}

void DFT(int G[MAX][MAX], int V) {
    int visited[MAX] = {0}, finishTime[MAX], hasCycle = 0;

    printf("DFS Traversal Order: ");
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFTUtil(G, V, i, visited, &hasCycle, finishTime);
        }
    }

    printf("\nCycle in graph: %s\n", hasCycle ? "Yes" : "No");
    
    printf("Finishing times:\n");
    for (int i = 0; i < V; i++) {
        printf("Node %d: %d\n", i, finishTime[i]);
    }
}

int main() {
    int V, isDirected;
    int G[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Is the graph directed (1 for yes, 0 for no)? ");
    scanf("%d", &isDirected);

    // a. Test if G is complete
    if (isComplete(G, V)) {
        printf("Graph is complete.\n");
    } else {
        printf("Graph is not complete.\n");
    }

    // a. Obtain degree/indegree/outdegree
    int node;
    printf("Enter node to get degree information: ");
    scanf("%d", &node);
    getDegree(G, V, node, isDirected);

    // a. Path existence
    int start, end;
    printf("Enter two vertices to check for path (start end): ");
    scanf("%d", &start, &end);
    if (pathExists(G, V, start, end)) {
        printf("Path exists between %d and %d.\n", start, end);
    } else {
        printf("No path exists between %d and %d.\n", start, end);
    }

    // b. Breadth-First Traversal
    printf("Enter source vertex for BFS: ");
    scanf("%d", &start);
    BFT(G, V, start);

    // c. Depth-First Traversal
    DFT(G, V);

    return 0;
}
