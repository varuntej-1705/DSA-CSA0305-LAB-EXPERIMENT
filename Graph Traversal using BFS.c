#include <stdio.h>
#define SIZE 10

int q[SIZE], front=0, rear=0;
void enqueue(int v){ q[rear++]=v; }
int dequeue(){ return q[front++]; }
int isEmpty(){ return front==rear; }

void bfs(int adj[SIZE][SIZE], int n, int start){
    int visited[SIZE]={0};
    enqueue(start); visited[start]=1;
    while(!isEmpty()){
        int v=dequeue();
        printf("%d ",v);
        for(int i=0;i<n;i++){
            if(adj[v][i] && !visited[i]){
                enqueue(i); visited[i]=1;
            }
        }
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
    printf("BFS starting from 0: ");
    bfs(adj,n,0);
}
