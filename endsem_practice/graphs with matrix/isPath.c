#include <stdio.h>

#define MAX 100

int adjMatrix[MAX][MAX];   // Adjacency matrix
int visited[MAX];          // Array to track visited nodes

// Function to perform DFS traversal
int dfs(int start, int end, int vertices) {
    visited[start] =1;

    if(start == end) return 1;

    for(int i =0;i<vertices; i++){
        if(adjMatrix[start][i] && !visited[i]){
            if(dfs(i,end,vertices)){
                return 1;
            }

        }
    }
    return 0;
}


int isPath(int start, int end, int vertices) {
   
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    return dfs(start, end, vertices);
}

int main() {
    int vertices;
    int start, end;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Input the start and end vertices to check for a path
    printf("Enter the start vertex: ");
    scanf("%d", &start);
    printf("Enter the end vertex: ");
    scanf("%d", &end);

    // Check for a path
    if (isPath(start, end, vertices)) {
        printf("There is a path between vertex %d and vertex %d.\n", start, end);
    } else {
        printf("There is no path between vertex %d and vertex %d.\n", start, end);
    }

    return 0;
}
