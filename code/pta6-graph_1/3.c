#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define N 7

int graph[N][N] = {
    {  0,   3,   3,   6, INF, INF, INF},  // 1
    {INF,   0, INF,   2,   5, INF, INF},  // 2
    {INF, INF,   0,   3, INF,   3, INF},  // 3
    {INF, INF, INF,   0,   2,   2,   5},  // 4
    {INF, INF, INF, INF,   0, INF,   3},  // 5
    {INF, INF, INF, INF, INF,   0,   4},  // 6
    {INF, INF, INF, INF, INF, INF,   0},  // 7
};

// 找到图中所有节点的最早完成时间（最长路径）
void calculateEC(int graph[N][N], int EC[N]) {
    for (int i = 0; i < N; i++) {
        EC[i] = 0;
    }

    // 按照拓扑顺序更新 EC
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (graph[u][v] != INF) {
                if (EC[v] < EC[u] + graph[u][v]) {
                    EC[v] = EC[u] + graph[u][v];
                }
            }
        }
    }
}

// 找到反向图中所有节点的最晚完成时间（最长路径）
void calculateLC(int graph[N][N], int EC[N], int LC[N]) {
    for (int i = 0; i < N; i++) {
        LC[i] = EC[N - 1];
    }

    // 按照反向拓扑顺序更新 LC
    for (int u = N - 1; u >= 0; u--) {
        for (int v = 0; v < N; v++) {
            if (graph[u][v] != INF) {
                if (LC[u] > LC[v] - graph[u][v]) {
                    LC[u] = LC[v] - graph[u][v];
                }
            }
        }
    }
}

int main() {
    int u, v, node;
    int EC[N], LC[N];

    // 输入删除的边 (u, v) 和查询节点
    scanf("%d,%d,%d", &u, &v, &node);

    // 删除边 (u, v)
    graph[u - 1][v - 1] = INF;

    // 计算最早完成时间 EC
    calculateEC(graph, EC);

    // 计算最晚完成时间 LC
    calculateLC(graph, EC, LC);

    // 计算 Slack 时间
    int slackTime = LC[node - 1] - EC[node - 1];
    printf("%d\n", slackTime);

    return 0;
}
