#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];

bool isComplete(int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (i != j && adjMatrix[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int vertices;

    printf("enter the number of vertices \n");
    scanf("%d", &vertices);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    if (isComplete(vertices))
    {
        printf("The graph is complete.\n");
    }
    else
    {
        printf("The graph is not complete.\n");
    }
}