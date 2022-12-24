#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTICES 10
typedef struct {
    int num_vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    char vertices[MAX_VERTICES];
} Graph;
int visited[MAX_VERTICES];
Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    // Initialize all vertices to 'A', 'B', etc.
    for (int i = 0; i < num_vertices; i++) {
        graph->vertices[i] = 'A' + i;
    }
    // Initialize all entries in adjacency matrix to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}
void add_edge(Graph* graph, int src, int dest) {
    graph->adjacency_matrix[src][dest] = 1;
}

Graph* removeV(Graph*graph, int vertex){
    for (int i = vertex; i < MAX_VERTICES - 1; i++) {
        graph->vertices[i] = graph->vertices[i + 1];
    }
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = vertex; j < graph->num_vertices - 1; j++) {
            graph->adjacency_matrix[i][j] = graph->adjacency_matrix[i][j + 1];
        }
    }
    for (int i = vertex; i < graph->num_vertices - 1; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            graph->adjacency_matrix[i][j] = graph->adjacency_matrix[i + 1][j];
        }
    }
    graph->num_vertices--;
    return graph;
}
void dfs(Graph*graph,int v) {
    printf("%c   ", graph->vertices[v]);
    visited[v] = 1;
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[v][i] && !visited[i]) {
            dfs(graph,i);
        }
    }
}
//It is also worth noting that this operation has a time complexity of O(VA2), where V is the number of vertices in the graph, so it may not be efficient for large graphs.
int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 0, 3);
    add_edge(graph, 1, 0);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 0);
    add_edge(graph, 3, 1);
    add_edge(graph, 3, 2);
    add_edge(graph, 3, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 1);
    add_edge(graph, 4, 3);
    graph=removeV(graph,2);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    // for(int i=0;i<graph->num_vertices;i++){
    //     printf("%c-",graph->vertices[i]);
    // }
    dfs(graph,0);
    return 0;
}

