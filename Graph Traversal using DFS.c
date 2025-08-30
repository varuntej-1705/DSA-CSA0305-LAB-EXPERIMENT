#include <stdio.h>
#define SIZE 10

void dfs(int adj[SIZE][SIZE], int n, int v, int visited[]){
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<n;i++){
        if(adj[v][i] && !visited[i])
            dfs(adj,n,i,visited);
    }
}

int main(){
    int n=5;
    int adj[SIZE][SIZE]={
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,1},
        {0,1,0,1,0}
    };
    int visited[SIZE]={0};
    printf("DFS starting from 0: ");
    dfs(adj,n,0,visited);
}
