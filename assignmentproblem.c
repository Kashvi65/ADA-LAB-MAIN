#include <stdio.h>
#define INF 9999

int main() {
    int n;
    printf("Enter number of workers/tasks: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int assigned[n];
    for (int i = 0; i < n; i++) assigned[i] = 0;

    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        int min = INF, min_index = -1;
        for (int j = 0; j < n; j++) {
            if (!assigned[j] && cost[i][j] < min) {
                min = cost[i][j];
                min_index = j;
            }
        }
        assigned[min_index] = 1;
        totalCost += min;
        printf("Assign Worker %d to Task %d (Cost = %d)\n", i + 1, min_index + 1, min);
    }

    printf("Total Minimum Cost: %d\n", totalCost);

    return 0;
}
