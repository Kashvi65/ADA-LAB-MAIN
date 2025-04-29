#include <stdio.h>

#define V 10
int adj[V][V], visited[V], n, cost = 0;

void tsp(int c) {
    int i, min = 999, next = 999;
    visited[c] = 1;

    printf("%d -> ", c + 1);

    for (i = 0; i < n; i++) {
        if ((adj[c][i] != 0) && (visited[i] == 0)) {
            if (adj[c][i] < min) {
                min = adj[c][i];
                next = i;
            }
        }
    }

    if (next == 999) {
        next = 0;
        cost += adj[c][next];
        printf("%d\n", next + 1);
        printf("Minimum cost: %d\n", cost);
        return;
    }

    cost += adj[c][next];
    tsp(next);
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Path: ");
    tsp(0); // Start from city 0
    return 0;
}
