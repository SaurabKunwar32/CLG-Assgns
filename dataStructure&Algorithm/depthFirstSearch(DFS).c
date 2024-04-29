#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent a graph node
struct GraphNode {
    int data;
    struct GraphNode* next;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    struct GraphNode** adjList;
};

// Function to create a new graph node
struct GraphNode* createNode(int value) {
    struct GraphNode* newNode = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->adjList = (struct GraphNode**)malloc(numVertices * sizeof(struct GraphNode*));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct GraphNode* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Depth-First Search (DFS) function
void DFSUtil(struct Graph* graph, int vertex, bool visited[]) {
    // Mark the current vertex as visited and print it
    visited[vertex] = true;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct GraphNode* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex])
            DFSUtil(graph, adjVertex, visited);
        temp = temp->next;
    }
}

// Function to perform Depth-First Search (DFS) traversal starting from a given vertex
void DFS(struct Graph* graph, int startVertex) {
    // Create a boolean array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false};

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, startVertex, visited);
}

// Main function
int main() {
    // Create a sample graph
    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printf("Depth-First Search (DFS) traversal starting from vertex 0:\n");
    DFS(graph, 0);

    return 0;
}