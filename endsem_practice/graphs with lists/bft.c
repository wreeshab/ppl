#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Node{
    int vertex;
    struct Node* next;
};
struct Node* adjList[MAX];
int visited[MAX];
int distance[MAX];
int vertices;
int isDirected;
# define INF 100
struct Queue{
    int items[MAX];
    int front; 
    int rear;
};
struct Queue* initQueue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

int dequeue(struct Queue* q){
    int item;
    if(isEmpty(q)){
        puts("queue is empty");
        return -1;
    }else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            q->front= q->rear = -1;
        }
    }
    return item;
}

int enqueue(struct Queue* q,int data){
    if(q->rear == -1){
        q->front++;
    }
    q->items[++(q->rear)] = data;

    
}

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
    
    if (!isDirected) {  // For undirected graph, add an edge in both directions
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

void bfs(int startVertex){
    struct Queue* q = initQueue();

    for(int i =0; i< vertices; i++){
        visited[i]=0;
        distance[i] = INF;
    }

    visited[startVertex] = 1;
    distance[startVertex] = 0;
    enqueue(q, startVertex);
    while(!isEmpty(q)){
        int current = dequeue(q);
        printf("%d ", current);
        struct Node* temp = adjList[startVertex];
        while(temp){
            int adjVertex = temp->vertex;
            if(!visited[adjVertex]){
                visited[adjVertex] =1;
                distance[adjVertex] = distance[current] + 1;
                enqueue(q,adjVertex);
            }
            temp = temp->next;
        }

    }
}


int main() {
    int edges, u, v, startVertex;

    // Input the number of vertices and whether the graph is directed
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter 1 if the graph is directed, 0 if undirected: ");
    scanf("%d", &isDirected);

    // Initialize adjacency list
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    // Input edges
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Input source vertex for BFS
    printf("Enter the source vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS
    bfs(startVertex);

    // Output the shortest distance from source
    printf("Shortest distance from vertex %d:\n", startVertex);
    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INF) {
            printf("Vertex %d is unreachable\n", i);
        } else {
            printf("Vertex %d: %d\n", i, distance[i]);
        }
    }

    return 0;
}