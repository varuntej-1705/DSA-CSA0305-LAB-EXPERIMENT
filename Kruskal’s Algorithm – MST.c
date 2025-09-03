#include <stdio.h>
#define MAX 30

int parent[MAX];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int n, int cost[MAX][MAX]) {
    int i, j, u, v, min, edges = 0, total_cost = 0;

    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in MST:\n");
    while(edges < n - 1) {
        min = 9999;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(cost[i][j] < min && find(i) != find(j)) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        unionSet(u, v);
        printf("%d -> %d = %d\n", u, v, min);
        total_cost += min;
        cost[u][v] = cost[v][u] = 9999;
        edges++;
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

    kruskal(n, cost);
    return 0;
}
