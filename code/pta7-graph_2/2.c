#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Edge structure
typedef struct {
    int u, v, w;
} Edge;

// Graph structure
typedef struct {
    int V, E;
    Edge edges[MAX];
} Graph;

// Find function for union-find (disjoint set)
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Union function for union-find
void union_set(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset) {
        parent[xset] = yset;
    }
}

// Comparator function to sort edges by weight
int compare(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->w - edgeB->w;
}

// Kruskal's algorithm to find MST
void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[MAX];  // Store the resultant MST
    int e = 0;  // Index for result[]
    int i = 0;  // Index for sorted edges

    // Step 1: Sort all edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compare);

    // Allocate memory for creating V subsets
    int *parent = (int*) malloc(V * sizeof(int));

    // Initialize all vertices as separate subsets
    for (int v = 0; v < V; ++v)
        parent[v] = -1;

    // Number of edges to be taken is V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. Check if it forms a cycle with the MST
        Edge next_edge = graph->edges[i++];

        int x = find(parent, next_edge.u);
        int y = find(parent, next_edge.v);

        // If including this edge does not cause a cycle, include it in the result
        if (x != y) {
            result[e++] = next_edge;
            union_set(parent, x, y);
        }
    }

    // Print the resultant MST in the specified format
    for (i = 0; i < e; ++i) {
        printf("%d", result[i].w);
        if (i < e - 1) {
            printf(",");
        }
    }
    printf(",\n");

    free(parent);
}

int main() {
    Graph graph;
    int new_weight;
    char modify_u, modify_v;

    // Hardcoded graph based on the image provided
    graph.V = 10;
    graph.E = 19;

    // A 0
    // B 1
    // C 2
    // D 3
    // E 4
    // F 5
    // G 6
    // H 7
    // I 8
    // J 9

    // Input all edges
    graph.edges[0] = (Edge){0, 1, 3};  // A - B
    graph.edges[1] = (Edge){0, 3, 4};  // A - D
    graph.edges[2] = (Edge){1, 2, 10}; // B - C
    graph.edges[3] = (Edge){1, 4, 2};  // B - E
    graph.edges[4] = (Edge){2, 5, 6};  // C - F
    graph.edges[5] = (Edge){3, 4, 5};  // D - E
    graph.edges[6] = (Edge){3, 7, 6};  // D - H
    graph.edges[7] = (Edge){4, 5, 11}; // E - F
    graph.edges[8] = (Edge){4, 8, 1};  // E - I
    graph.edges[9] = (Edge){5, 6, 2};  // F - G
    graph.edges[10] = (Edge){5, 9, 11}; // F - J
    graph.edges[11] = (Edge){7, 8, 4}; // H - I
    graph.edges[12] = (Edge){8, 9, 7}; // I - J
    graph.edges[13] = (Edge){6, 9, 8}; // G - J
    graph.edges[14] = (Edge){6, 2, 1}; // G - C
    graph.edges[15] = (Edge){5, 1, 3}; // F - B
    graph.edges[16] = (Edge){0, 4, 4}; // A - E
    graph.edges[17] = (Edge){4, 7, 2}; // E - H
    graph.edges[18] = (Edge){5, 8, 3}; // F - I

    // Input the edge to modify
    scanf("%c,%c,%d", &modify_u, &modify_v, &new_weight);

    int u = modify_u - 'A';
    int v = modify_v - 'A';

    // Modify the specified edge
    for (int i = 0; i < graph.E; i++) {
        if((graph.edges[i].u == u && graph.edges[i].v == v) || (graph.edges[i].u == v && graph.edges[i].v == u)) {
            graph.edges[i].w = new_weight;
            break;
        }
    }

    // Print the modified graph
    /*
    for (int i = 0; i < graph.E; i++) {
        printf("%d,%d,%d\n", graph.edges[i].u, graph.edges[i].v, graph.edges[i].w);
    }
    */

    // Find the Minimum Spanning Tree
    kruskalMST(&graph);

    return 0;
}
