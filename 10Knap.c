#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int W, int w[], int v[]) {
    int V[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            } else if (j - w[i - 1] >= 0) {
                V[i][j] = max(V[i - 1][j], v[i - 1] + V[i - 1][j - w[i - 1]]);
            } else {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    return V[n][W];
}

int main() {
    int n, W;
    int weights[MAX_ITEMS], values[MAX_ITEMS];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("Enter weights of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter values of %d items:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int result = knapsack(n, W, weights, values);
    printf("Maximum value that can be put in the knapsack = %d\n", result);

    return 0;
}
