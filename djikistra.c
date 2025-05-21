#include <stdio.h>
#define INF 99999 // Represents infinity
#define MAX 100 // Maximum number of vertices
int minDistance(int dist[], int visited[], int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[], int src, int V) {
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX], visited[MAX];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist, src, V);
}
int main() {
    int graph[MAX][MAX];
    int V, source;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);
    dijkstra(graph, source, V);
    return 0;
}