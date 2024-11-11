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
    int hasCycle;
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
    g->hasCycle = 0;

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

// Depth-First Traversal (DFS) function
void dft(struct Graph* graph, int startVertex) {
    graph->visited[startVertex] = 1;  // Mark as visited (partially processed)
    struct Node* temp = graph->adjacencyList[startVertex];
    
    while (temp) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {  // Not visited
            dft(graph, connectedVertex);
        } else if (graph->visited[connectedVertex] == 1) {  // Back edge found
            graph->hasCycle = 1;
        }
        temp = temp->next;
    }
    graph->visited[startVertex] = 2;  // Fully processed
    graph->finishTime[startVertex] = ++graph->time;
    printf("Vertex %d finish time: %d\n", startVertex, graph->finishTime[startVertex]);
}

// Wrapper function for DFS traversal
void dftWrapper(struct Graph* graph) {
    for (int i = 0; i < graph->n; i++) {
        graph->visited[i] = 0;
    }

    printf("DFS Order:\n");
    for (int i = 0; i < graph->n; i++) {
        if (graph->visited[i] == 0) {
            dft(graph, i);
        }
    }

    if (graph->hasCycle) {
        printf("The graph has a cycle.\n");
    } else {
        printf("The graph does not have a cycle.\n");
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

    dftWrapper(graph);

    return 0;
}
