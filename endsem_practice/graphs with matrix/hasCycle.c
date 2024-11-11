#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];

int dfs(int startVertex, int vertices, int parent)
{
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    for (int i = 0; i < vertices; i++)
    {
        if (adjMatrix[startVertex][i])
        {
            if (!visited[i])
            {
                if (dfs(i, vertices, startVertex))
                {
                    return 1;
                }
            }
            else if (i != parent)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int vertices;
    puts("enter the number of vertices");
    scanf("%d", &vertices);
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }
        int cycle = dfs(i, vertices, -1);
        puts("");
        if (cycle)
        {
            printf("yes cycle \n");
            break;
        }
    }
}