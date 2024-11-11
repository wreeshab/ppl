#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int vertices;
int isDirected;

int isComplete()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i != j && !adjMatrix[i][j])
                return 0;
        }
    }
    return 1;
}
void printDegree()
{
    int outDegree = 0;
    int inDegree = 0;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adjMatrix[i][j])
                outDegree++;
            if (adjMatrix[j][i])
                inDegree++;
        }

        if (isDirected)
        {
            printf("indegree: %d and outdegree %d\n", inDegree, outDegree);
        }
        else
        {
            printf("degreee: %d\n", outDegree);
        }
    }
}

int isPath(int startVertex, int endVertex)
{
    visited[startVertex] = 1;
    if (startVertex == endVertex)
        return 1;

    for (int i = 0; i < vertices; i++)
    {
        if (adjMatrix[startVertex][i] && !visited[i])
        {
            if (isPath(i, endVertex))
                return 1;
        }
    }
    return 0;
}

int main()
{
    printf("enter the number of vertices\n");
    scanf("%d", &vertices);
    puts("1 for directed and 0 for undirected");
    scanf("%d", &isDirected);

    puts("enter the matrix");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    if (!isDirected)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[j][i] = adjMatrix[i][j];
            }
        }
    };
    if (isComplete())
    {
        puts("complete");
    }
    else
    {
        puts("not comleye");
    }

    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
}