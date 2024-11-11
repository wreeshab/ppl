#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];

void dfs(int startVertex, int vertices){
    visited[startVertex] =1;
    printf("%d ", startVertex);

    for(int i =0;i<vertices; i++){
        if(adjMatrix[startVertex][i] && !visited[i]){
            dfs(i,vertices);
        }
    }
}




int main(){
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
    
    for(int i=0 ;i<vertices;i++){
        visited[i] =0;
    }
    dfs(0,vertices);


}