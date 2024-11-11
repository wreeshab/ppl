#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    struct Node** adjacencyList;
    int* visited;
    int* finishTime;
    int n;
    int time;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->n = vertices;
    g->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    g->visited = (int*)malloc(vertices * sizeof(int));
    g->finishTime = (int*)malloc(vertices * sizeof(int));
    g->time = 0;

    for (int i = 0; i < vertices; i++) {
        g->adjacencyList[i] = NULL;
        g->visited[i] = 0;
        g->finishTime[i] = -1;
    }

    return g;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int isDirected) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Add an edge in the opposite direction for an undirected graph
    if (!isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjacencyList[dest];
        graph->adjacencyList[dest] = newNode;
    }
}

// DFS function with cycle detection and finishing time
void dfs(struct Graph* graph, int vertex, int* hasCycle) {
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    struct Node* adjList = graph->adjacencyList[vertex];
    struct Node* temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            dfs(graph, connectedVertex, hasCycle);
        } else if (graph->visited[connectedVertex] == 1) {
            *hasCycle = 1;  // Cycle detected
        }
        temp = temp->next;
    }
    
    graph->visited[vertex] = 2;  // Mark as fully explored
    graph->finishTime[vertex] = ++graph->time;
}

// Wrapper function for DFS traversal and cycle detection
void dfsTraversal(struct Graph* graph) {
    int hasCycle = 0;
    printf("DFS Traversal Order:\n");

    for (int i = 0; i < graph->n; i++) {
        if (graph->visited[i] == 0) {
            dfs(graph, i, &hasCycle);
        }
    }

    // Print finishing times
    printf("\nFinishing Times:\n");
    for (int i = 0; i < graph->n; i++) {
        printf("Vertex %d: %d\n", i, graph->finishTime[i]);
    }

    // Print if the graph has a cycle
    if (hasCycle) {
        printf("\nThe graph has a cycle.\n");
    } else {
        printf("\nThe graph does not have a cycle.\n");
    }
}

// Main function
int main() {
    int vertices, edges, isDirected;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter 1 for directed graph, 0 for undirected graph: ");
    scanf("%d", &isDirected);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest, isDirected);
    }

    // Perform DFS traversal and detect cycles
    dfsTraversal(graph);

    // Free memory
    free(graph->adjacencyList);
    free(graph->visited);
    free(graph->finishTime);
    free(graph);

    return 0;
}
