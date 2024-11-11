#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];

void calculateDegree(int vertices,int isDirected){
    if(isDirected){
        for(int i =0; i<vertices;i++){
            int outDegree=0; 
            int inDegree=0;
            for(int j=0; j<vertices;j++){
                if(adjMatrix[i][j] ==1) outDegree++;
                if(adjMatrix[j][i] ==1) inDegree++;
            }
            printf("vertex %d indegree = %d , ourdegree = %d", i+1, inDegree, outDegree);
        }
    }else{
        for (int i = 0; i < vertices; i++)
        {
            int degree =0;
            for(int j =0; j<vertices;j++){
                if(adjMatrix[i][j]) degree++;
            }
            printf("vertex %d degree = %d ", i+1, degree);
        }
        
    }
}

int main()
{
    int vertices;
    int isDirected;

    printf("enter the number of vertices \n");
    scanf("%d", &vertices);

    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &isDirected);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    calculateDegree(vertices,isDirected);


}