#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adjList[MAX];
int visited[MAX];
int isDirected;
int vertices;
int edges;

void addEdge(int u, int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = adjList[u];
    newNode->vertex = v;
    adjList[u] = newNode;

    if (!isDirected)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->vertex = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
}

int isComplete()
{
    for (int i = 0; i < vertices; i++)
    {
        int count = 0;
        struct Node *temp = adjList[i];
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (count != vertices - 1)
        {
            return 0;
        }
    }
    return 1;
}
void getDegree(int u)
{
    int inDegree = 0;
    int outDegree = 0;
    struct Node *temp = adjList[u];

    while (temp != NULL)
    {
        temp = temp->next;
        outDegree++;
    }
    if (isDirected)
    {
        for (int i = 0; i < vertices; i++)
        {
            struct Node *temp = adjList[i];
            while (temp != NULL)
            {
                if (temp->vertex == u)
                {
                    inDegree++;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    if (isDirected)
    {
        printf("the indegree is %d ", inDegree);
        puts("");
        printf("the outdegree is %d,", outDegree);
    }
    else
    {
        printf("the degree of this graph is %d", outDegree);
    }
}

int dfs(int startVertex, int endVertex){
    visited[startVertex] = 1;

    if(startVertex == endVertex) return 1;

    struct Node* temp = adjList[startVertex];
    while(temp){
        if(!visited[temp->vertex]){
            if(dfs(temp->vertex, endVertex)) return 1 ;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    int u, v,start,end;
    puts("enter the number of vertices");
    scanf("%d", &vertices);
    puts("enter the number of edges");
    scanf("%d", &edges);
    puts("1 for directed and 0 for undirected");
    scanf("%d", &isDirected);

    for (int i = 0; i < vertices; i++)
    {
        adjList[i] = NULL;
        visited[i]= 0;
    }
    for (int i = 0; i < edges; i++)
    {
        printf("enter source u and dest v (u, v)");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    if (isComplete())
    {
        puts("the given graph is complte");
    }
    else
    {
        puts("the graph is not complete");
    }
    for(int i=0;i<vertices;i++){
        printf("the degrees of %d \n" , i);
        getDegree(i);
        puts("");
    }

    printf("\nEnter two vertices to check if there exists a path (start end): ");
    scanf("%d %d", &start, &end);

    if (dfs(start, end)) {
        printf("There exists a path between %d and %d.\n", start, end);
    } else {
        printf("No path exists between %d and %d.\n", start, end);
    }
    
}
