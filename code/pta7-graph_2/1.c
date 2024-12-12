#include <stdio.h>
#define INF 99999
#define V 7

int minDistance(int dist[], int sptSet[])
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src, int dest)
{
    int dist[V];  
    int sptSet[V]; 
    int parent[V]; 

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }

    if (dist[dest] == INF) {
        printf("-1\n");
    } else {
        int path[V];
        int index = 0;
        for (int v = dest; v != -1; v = parent[v])
            path[index++] = v;

        for (int i = index - 1; i >= 0; i--) {
            printf("%d%s", path[i] + 1, (i == 0) ? ",\n" : ",");
        }
    }
}

int main()
{
    int graph[V][V] = {
        {0, 2, INF, 1, INF, INF, INF},
        {INF, 0, INF, 3, 10, INF, INF},
        {4, INF, 0, INF, INF, 5, INF},
        {INF, INF, 2, 0, 2, 8, 4},
        {INF, INF, INF, INF, 0, INF, 6},
        {INF, INF, INF, INF, INF, 0, INF},
        {INF, INF, INF, INF, INF, 1, 0}
    };

    int src, dest;
    scanf("%d,%d", &src, &dest);

    src--;
    dest--;

    dijkstra(graph, src, dest);

    return 0;
}
