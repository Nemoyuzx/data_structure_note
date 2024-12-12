#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 11
#define MAX_NAME_LEN 2

typedef struct {
    char name[MAX_NAME_LEN];
    int out_degree;
    int edges[MAX_NODES];
    int weights[MAX_NODES];  // Array to store weights of edges
} Node;

Node graph[MAX_NODES];
int in_degree[MAX_NODES];
char *nodes[MAX_NODES] = {"S", "A", "B", "C", "D", "E", "F", "G", "H", "I", "T"};

int get_node_index(char *name) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (strcmp(nodes[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

void initialize_graph() {
    for (int i = 0; i < MAX_NODES; i++) {
        strcpy(graph[i].name, nodes[i]);
        graph[i].out_degree = 0;
    }

    // Graph representation with weights based on the given image
    graph[get_node_index("S")].edges[graph[get_node_index("S")].out_degree] = get_node_index("A");
    graph[get_node_index("S")].weights[graph[get_node_index("S")].out_degree++] = 1;
    
    graph[get_node_index("S")].edges[graph[get_node_index("S")].out_degree] = get_node_index("D");
    graph[get_node_index("S")].weights[graph[get_node_index("S")].out_degree++] = 4;
    
    graph[get_node_index("S")].edges[graph[get_node_index("S")].out_degree] = get_node_index("G");
    graph[get_node_index("S")].weights[graph[get_node_index("S")].out_degree++] = 6;

    graph[get_node_index("A")].edges[graph[get_node_index("A")].out_degree] = get_node_index("B");
    graph[get_node_index("A")].weights[graph[get_node_index("A")].out_degree++] = 2;
    
    graph[get_node_index("A")].edges[graph[get_node_index("A")].out_degree] = get_node_index("E");
    graph[get_node_index("A")].weights[graph[get_node_index("A")].out_degree++] = 2;

    graph[get_node_index("B")].edges[graph[get_node_index("B")].out_degree] = get_node_index("C");
    graph[get_node_index("B")].weights[graph[get_node_index("B")].out_degree++] = 2;

    graph[get_node_index("C")].edges[graph[get_node_index("C")].out_degree] = get_node_index("T");
    graph[get_node_index("C")].weights[graph[get_node_index("C")].out_degree++] = 4;

    graph[get_node_index("D")].edges[graph[get_node_index("D")].out_degree] = get_node_index("E");
    graph[get_node_index("D")].weights[graph[get_node_index("D")].out_degree++] = 3;
    
    graph[get_node_index("D")].edges[graph[get_node_index("D")].out_degree] = get_node_index("A");
    graph[get_node_index("D")].weights[graph[get_node_index("D")].out_degree++] = 3;

    graph[get_node_index("E")].edges[graph[get_node_index("E")].out_degree] = get_node_index("C");
    graph[get_node_index("E")].weights[graph[get_node_index("E")].out_degree++] = 2;
    
    graph[get_node_index("E")].edges[graph[get_node_index("E")].out_degree] = get_node_index("F");
    graph[get_node_index("E")].weights[graph[get_node_index("E")].out_degree++] = 3;
    
    graph[get_node_index("E")].edges[graph[get_node_index("E")].out_degree] = get_node_index("I");
    graph[get_node_index("E")].weights[graph[get_node_index("E")].out_degree++] = 3;

    graph[get_node_index("F")].edges[graph[get_node_index("F")].out_degree] = get_node_index("T");
    graph[get_node_index("F")].weights[graph[get_node_index("F")].out_degree++] = 3;
    
    graph[get_node_index("F")].edges[graph[get_node_index("F")].out_degree] = get_node_index("C");
    graph[get_node_index("F")].weights[graph[get_node_index("F")].out_degree++] = 1;

    graph[get_node_index("G")].edges[graph[get_node_index("G")].out_degree] = get_node_index("H");
    graph[get_node_index("G")].weights[graph[get_node_index("G")].out_degree++] = 6;
    
    graph[get_node_index("G")].edges[graph[get_node_index("G")].out_degree] = get_node_index("E");
    graph[get_node_index("G")].weights[graph[get_node_index("G")].out_degree++] = 1;
    
    graph[get_node_index("G")].edges[graph[get_node_index("G")].out_degree] = get_node_index("D");
    graph[get_node_index("G")].weights[graph[get_node_index("G")].out_degree++] = 2;

    graph[get_node_index("H")].edges[graph[get_node_index("H")].out_degree] = get_node_index("E");
    graph[get_node_index("H")].weights[graph[get_node_index("H")].out_degree++] = 2;
    
    graph[get_node_index("H")].edges[graph[get_node_index("H")].out_degree] = get_node_index("I");
    graph[get_node_index("H")].weights[graph[get_node_index("H")].out_degree++] = 6;

    graph[get_node_index("I")].edges[graph[get_node_index("I")].out_degree] = get_node_index("T");
    graph[get_node_index("I")].weights[graph[get_node_index("I")].out_degree++] = 4;
    
    graph[get_node_index("I")].edges[graph[get_node_index("I")].out_degree] = get_node_index("F");
    graph[get_node_index("I")].weights[graph[get_node_index("I")].out_degree++] = 1;
}

void calculate_in_degrees() {
    for (int i = 0; i < MAX_NODES; i++) {
        in_degree[i] = 0;
    }
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < graph[i].out_degree; j++) {
            int neighbor = graph[i].edges[j];
            in_degree[neighbor]++;
        }
    }
}

void remove_edge(char *start, char *end) {
    int start_index = get_node_index(start);
    int end_index = get_node_index(end);

    for (int i = 0; i < graph[start_index].out_degree; i++) {
        if (graph[start_index].edges[i] == end_index) {
            for (int j = i; j < graph[start_index].out_degree - 1; j++) {
                graph[start_index].edges[j] = graph[start_index].edges[j + 1];
                graph[start_index].weights[j] = graph[start_index].weights[j + 1];
            }
            graph[start_index].out_degree--;
            in_degree[end_index]--;
            break;
        }
    }
}

void topological_sort() {
    // Sort the edges based on weight for each node
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < graph[i].out_degree - 1; j++) {
            for (int k = 0; k < graph[i].out_degree - j - 1; k++) {
                if (graph[i].weights[k] > graph[i].weights[k + 1]) {
                    // Swap edges
                    int temp_edge = graph[i].edges[k];
                    graph[i].edges[k] = graph[i].edges[k + 1];
                    graph[i].edges[k + 1] = temp_edge;
                    
                    // Swap weights
                    int temp_weight = graph[i].weights[k];
                    graph[i].weights[k] = graph[i].weights[k + 1];
                    graph[i].weights[k + 1] = temp_weight;
                }
            }
        }
    }
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int top_order[MAX_NODES];
    int index = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int current = queue[front++];
        top_order[index++] = current;

        for (int i = 0; i < graph[current].out_degree; i++) {
            int neighbor = graph[current].edges[i];
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    for (int i = 0; i < index; i++) {
        if (i > 0) {
            printf(",");
        }
        printf("%s", nodes[top_order[i]]);
    }
    printf(",\n");
}

int main() {
    char input_edge[5];
    //printf("Enter the edge to remove (format A,B): ");
    scanf("%s", input_edge);

    char start_node[MAX_NAME_LEN], end_node[MAX_NAME_LEN];
    sscanf(input_edge, "%1[^,],%1s", start_node, end_node);

    initialize_graph();
    calculate_in_degrees();
    remove_edge(start_node, end_node);
    topological_sort();

    return 0;
}
