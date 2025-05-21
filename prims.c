#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF 9999999
int main() {
int cost[MAX][MAX];
int visited[MAX], minCost = 0;
int n, i, j, edges = 0;
printf("Enter number of vertices: ");
scanf("%d", &n);
printf("Enter the adjacency matrix (use 0 for no edge):\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &cost[i][j]);
if (cost[i][j] == 0)
cost[i][j] = INF;
}
visited[i] = 0;
}
visited[0] = 1;
printf("Edges in the Minimum Cost Spanning Tree:\n");
while (edges < n - 1) {
int min = INF, a = -1, b = -1;
for (i = 0; i < n; i++) {
if (visited[i]) {
for (j = 0; j < n; j++) {
if (!visited[j] && cost[i][j] < min) {
min = cost[i][j];
a = i;
b = j;
}
}
}
}
if (a != -1 && b != -1) {
printf("%d - %d : %d\n", a, b, cost[a][b]);
minCost += cost[a][b];
visited[b] = 1;
edges++;
}
}
printf("Total cost of Minimum Spanning Tree: %d\n", minCost);
return 0;
}