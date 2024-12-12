#include <stdio.h>
#define N 8

void dfs(int graph[N][N], int start, int visited[]) {
    // Mark the current node as visited and print it
    visited[start] = 1;
    printf("%d,", start + 1);

    // Traverse all the adjacent vertices
    for (int neighbor = 0; neighbor < N; neighbor++) {
        if (graph[start][neighbor] == 1 && !visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int adjacency_matrix[N][N] = {
        {0, 1, 1, 0, 0, 0, 0, 0},  // 1
        {1, 0, 0, 1, 1, 0, 0, 0},  // 2
        {1, 0, 0, 0, 0, 1, 1, 0},  // 3
        {0, 1, 0, 0, 0, 0, 0, 1},  // 4
        {0, 1, 0, 0, 0, 1, 0, 1},  // 5
        {0, 0, 1, 0, 0, 0, 0, 1},  // 6
        {0, 0, 1, 0, 0, 0, 0, 1},  // 7
        {0, 0, 0, 1, 1, 1, 1, 0}   // 8
    };

    // Initialize visited array
    int visited[N] = {0};

    // Input
    int start_vertex;
    scanf("%d", &start_vertex);
    start_vertex--;  // Convert to zero-based index

    // Perform DFS traversal
    dfs(adjacency_matrix, start_vertex, visited);

    printf("\n");

    return 0;
}
