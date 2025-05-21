#include <stdio.h>
#define INF 9999
int a[10][10], D[10][10], n;
void floyd(int a[][10], int);
int min(int, int);
int main() {
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (use %d for infinity):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    floyd(a, n);
    printf("Distance Matrix after Floyd-Warshall:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void floyd(int a[][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            D[i][j] = a[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (D[i][k] != INF && D[k][j] != INF)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}
int min(int a, int b) {
    return (a < b) ? a : b;
}