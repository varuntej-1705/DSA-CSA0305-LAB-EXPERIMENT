#include <stdio.h>
#define INF 9999
#define MAX 10

void prim(int n, int cost[MAX][MAX]) {
    int visited[MAX] = {0}, no_of_edges = 0;
    int min, u, v, i, j, total_cost = 0;

    visited[0] = 1;

    printf("Edges in MST:\n");
    while(no_of_edges < n - 1) {
        min = INF;
        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d -> %d = %d\n", u, v, min);
        total_cost += min;
        visited[v] = 1;
        no_of_edges++;
    }

    printf("Total cost of MST = %d\n", total_cost);
}

int main() {
    int n, cost[MAX][MAX], i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (use 9999 for INF):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prim(n, cost);
    return 0;
}
