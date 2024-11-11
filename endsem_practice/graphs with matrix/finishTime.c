#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int finishTime[MAX];
int time = 0;

void dfs(int startVertex, int vertices){
    visited[startVertex] = 1;
    printf("%d ",startVertex);

    for(int i = 0; i<vertices;i++){
        if(!visited[i] && adjMatrix[startVertex][i]){
            dfs(i,vertices);
        }
    }
    time++;
    finishTime[startVertex] = time;
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
        finishTime[i] =0;
    }
    dfs(0,vertices);
    puts("finish time");
    for (int i = 0; i <vertices; i++)
    {
        printf("%d ", finishTime[i]);
    }
    


}