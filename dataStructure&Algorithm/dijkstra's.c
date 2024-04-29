#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent a graph node
struct GraphNode {
    int dest;
    int weight;
    struct GraphNode* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct GraphNode** adjList;
};

// Function to create a new graph node
struct GraphNode* createNode(int dest, int weight) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct GraphNode**)malloc(numVertices * sizeof(struct GraphNode*));
    for (int i = 0; i < numVertices; ++i)
        graph->adjList[i] = NULL;
    return graph;
}

// Function to add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct GraphNode* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; ++v) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest distances from the source vertex
void printSolution(int dist[], int V) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm
void dijkstra(struct Graph* graph, int src) {
    int V = graph->numVertices;
    int dist[V];
    bool visited[V];

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; ++count) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, visited, V);

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        struct GraphNode* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->dest;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[v])
                dist[v] = dist[u] + temp->weight;
            temp = temp->next;
        }
    }

    // Print the calculated shortest distances
    printSolution(dist, V);
}

// Main function
int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 5);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 1, 2);
    addEdge(graph, 2, 3, 9);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 4, 0, 7);
    addEdge(graph, 4, 3, 6);

    int sourceVertex = 0;
    printf("Shortest distances from source vertex %d:\n", sourceVertex);
    dijkstra(graph, sourceVertex);

    return 0;
}