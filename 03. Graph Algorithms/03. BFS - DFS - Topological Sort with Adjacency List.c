#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define CARDINALITY 7

struct Vertex {
    int value;
    struct Vertex *next;
};

typedef struct Vertex Vertex;

struct Graph {
    int cardinality;
    Vertex **adjacencyList;
};

typedef struct Graph Graph;

Vertex *createVertex(int);

Graph *createGraph(int vertices);

void addEdge(Graph *graph, int s, int d);

Graph *adjacencyMatrixToAdjacencyList(int matrix[][CARDINALITY], int vertices);

void printGraph(Graph *graph);

bool isTricolored(Graph *graph, int *color, int numberOfVertices);

int generateNonDeterministicNumber();

int main() {

    Graph *graph = createGraph(CARDINALITY);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);

    //printGraph(graph);

    int color[CARDINALITY + 1] = {0, 1, 1, 0, 2, 2, 2};

    /*for (int i = 0; i < CARDINALITY; ++i) {
        color[i]=generateNonDeterministicNumber();
        __VERIFIER_assume(color[i]==0 || color[i]==1 || color[i]==2);
    }*/

    //assert(!isTricolored(graph, color, CARDINALITY));

    int matrix[CARDINALITY][CARDINALITY] =
                       {{0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 0},
                        {1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 1, 0, 1, 1},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0}};

    Graph *graph1 = adjacencyMatrixToAdjacencyList(matrix, CARDINALITY);
    printGraph(graph1);

    int color1[CARDINALITY] = {0, 1, 2, 3, 1, 2, 2};

    assert(!isTricolored(graph1, color1, CARDINALITY));

    return 0;
}

Vertex *createVertex(int value) {

    Vertex *newVertex = malloc(sizeof(Vertex));
    newVertex->value = value;
    newVertex->next = NULL;

    return newVertex;
}

Graph *createGraph(int vertices) {

    Graph *graph = malloc(sizeof(Graph));
    graph->cardinality = vertices;
    graph->adjacencyList = malloc(vertices * sizeof(Vertex *));

    for (int i = 0; i < vertices; i++) {
        *(graph->adjacencyList + i) = NULL;
    }

    return graph;
}

void addEdge(Graph *graph, int sourceNode, int destinationNode) {

    Vertex *newVertex;

    newVertex = createVertex(destinationNode);
    newVertex->next = *(graph->adjacencyList + sourceNode);
    *(graph->adjacencyList + sourceNode) = newVertex;

    newVertex = createVertex(sourceNode);
    newVertex->next = *(graph->adjacencyList + destinationNode);
    *(graph->adjacencyList + destinationNode) = newVertex;
}

Graph *adjacencyMatrixToAdjacencyList(int matrix[][CARDINALITY], int vertices) {

    Graph *graph = malloc(sizeof(Graph));
    graph->cardinality = vertices;
    graph->adjacencyList = malloc(vertices * sizeof(Vertex *));

    for (int i = 0; i < vertices; i++) {
        *(graph->adjacencyList + i) = NULL;
    }

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < i+1; ++j) {
            if (matrix[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
    return graph;
}

void printGraph(Graph *graph) {

    for (int i = 0; i < graph->cardinality; i++) {

        Vertex *currentVertexAdjacentToI = *(graph->adjacencyList + i);
        printf("Vertex %d:\n", i);

        while (currentVertexAdjacentToI) {
            printf("%d -> ", currentVertexAdjacentToI->value);
            currentVertexAdjacentToI = currentVertexAdjacentToI->next;
        }

        printf("\n");
    }
}

bool isTricolored(Graph *graph, int *color, int numberOfVertices) {

    for (int i = 0; i < numberOfVertices; ++i) {

        Vertex *currentNode = *(graph->adjacencyList + i);

        while (currentNode != NULL) {
            if (color[i] == color[currentNode->value]) {
                return false;
            }
            currentNode = currentNode->next;
        }
    }
    return true;
}