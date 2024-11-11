#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
    int* startTime;
    int* finishTime;
    int* parent;
    int time;
    int isDirected;
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices, int isDirected) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    graph->startTime = (int*)malloc(vertices * sizeof(int));
    graph->finishTime = (int*)malloc(vertices * sizeof(int));
    graph->parent = (int*)malloc(vertices * sizeof(int));
    graph->time = 0;
    graph->isDirected = isDirected;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
        graph->startTime[i] = 0;
        graph->finishTime[i] = 0;
        graph->parent[i] = -1;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // If undirected, add edge from dest to src as well
    if (!graph->isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Depth First Search function with cycle detection and finishing times
int dfs(struct Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    graph->time++;
    graph->startTime[vertex] = graph->time;
    printf("%d ", vertex);  // Order of traversal

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;

        // If not visited, continue DFS
        if (!graph->visited[connectedVertex]) {
            graph->parent[connectedVertex] = vertex;
            if (dfs(graph, connectedVertex)) {
                return 1; // Cycle found
            }
        } else if (graph->visited[connectedVertex] == 1) {
            // Back edge found indicating a cycle
            if (graph->isDirected || connectedVertex != graph->parent[vertex]) {
                return 1;
            }
        }

        adjList = adjList->next;
    }

    graph->visited[vertex] = 2;
    graph->time++;
    graph->finishTime[vertex] = graph->time;
    return 0;
}

// Function to initialize DFS for all vertices and print results
void performDFS(struct Graph* graph) {
    int hasCycle = 0;
    printf("DFS Traversal Order: ");
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            if (dfs(graph, i)) {
                hasCycle = 1;
            }
        }
    }
    printf("\n");

    if (hasCycle) {
        printf("The graph has a cycle.\n");
    } else {
        printf("The graph has no cycle.\n");
    }

    printf("Finishing Times:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: Start = %d, Finish = %d\n", i, graph->startTime[i], graph->finishTime[i]);
    }
}

int main() {
    int vertices, edges, isDirected;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    struct Graph* graph = createGraph(vertices, isDirected);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (source and destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Perform DFS and output the traversal order, cycle presence, and finishing times
    performDFS(graph);

    return 0;
}
