#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

int graph[MAX_NODES][MAX_NODES];  // Adjacency matrix
int visited[MAX_NODES];  // Array to store visited nodes
struct Queue queue;  // Queue for breadth-first search

// Function to get the neighbors of a given node
void get_neighbors(int graph[][MAX_NODES], int node, int neighbors[], int *num_neighbors) {
    // Iterate over all the nodes
    for (int i = 0; i < MAX_NODES; i++) {
        // If there is an edge between the node and the current node, add it to the list of neighbors
        if (graph[node][i] == 1) {
            neighbors[(*num_neighbors)++] = i;
        }
    }
}

// Function to enqueue a node
void enqueue(int data) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (queue.rear == NULL) {
        queue.front = queue.rear = new_node;
        return;
    }
    queue.rear->next = new_node;
    queue.rear = new_node;
}

// Function to dequeue a node
int dequeue() {
    if (queue.front == NULL) {
        return -1;
    }
    struct Node *temp = queue.front;
    int data = temp->data;
    queue.front = temp->next;
    if (queue.front == NULL) {
        queue.rear = NULL;
    }
    free(temp);
    return data;
}

// Function to traverse the graph
void traverse_graph(int graph[][MAX_NODES], int start) {
    // Mark the start node as visited
    visited[start] = 1;

    // Add the start node to the queue
    enqueue(start);

    // Traverse the graph
    while (queue.front != NULL) {
        // Take the first node from the queue
        int node = dequeue();
        // Get the neighbors of the node
        int neighbors[MAX_NODES];
        int num_neighbors = 0;
        get_neighbors(graph, node, neighbors, &num_neighbors);
        // Mark the neighbors as visited
        for (int i = 0; i < num_neighbors; i++) {
            if (!visited[neighbors[i]]) {
                visited[neighbors[i]] = 1;
                enqueue(neighbors[i]);
            }
        }
    }
}
