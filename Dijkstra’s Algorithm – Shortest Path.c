#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int n, int cost[MAX][MAX], int start) {
    int dist[MAX], visited[MAX] = {0}, count, mindistance, nextnode, i, j;

    for(i = 0; i < n; i++) {
        dist[i] = cost[start][i];
    }
    visited[start] = 1;
    dist[start] = 0;

    for(count = 1; count < n - 1; count++) {
        mindistance = INF;
        for(i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < mindistance) {
                mindistance = dist[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;

        for(i = 0; i < n; i++) {
            if(!visited[i] && mindistance + cost[nextnode][i] < dist[i]) {
                dist[i] = mindistance + cost[nextnode][i];
            }
        }
    }

    printf("Shortest distances from source %d:\n", start);
    for(i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main() {
    int n, cost[MAX][MAX], i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 9999 for INF):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(n, cost, start);
    return 0;
}
