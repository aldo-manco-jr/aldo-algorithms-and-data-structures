#include <stdio.h>
#include <stdlib.h>

#define INFINITY 2147483647

typedef struct {
    int startingNode;
    int endingNode;
    int weight;
} Edge;

typedef struct {
    int cardinalityVertices;
    int cardinalityEdges;
    Edge *arrayEdges;
} Graph;

void bellmanFordSingleSourceShortestPath(Graph *graph, int singleSourceNode, int cardinalityVertices, int cardinalityEdges);

int main() {

    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->cardinalityVertices = 4;
    graph->cardinalityEdges = 5;

    graph->arrayEdges = (Edge *) malloc(graph->cardinalityEdges * sizeof(Edge));

    int singleSourceNode = 0;

    graph->arrayEdges[0].startingNode = 0;
    graph->arrayEdges[0].endingNode = 1;
    graph->arrayEdges[0].weight = 5;

    graph->arrayEdges[0].startingNode = 0;
    graph->arrayEdges[0].endingNode = 2;
    graph->arrayEdges[0].weight = 4;

    graph->arrayEdges[0].startingNode = 1;
    graph->arrayEdges[0].endingNode = 3;
    graph->arrayEdges[0].weight = 3;

    graph->arrayEdges[0].startingNode = 2;
    graph->arrayEdges[0].endingNode = 1;
    graph->arrayEdges[0].weight = 6;

    graph->arrayEdges[0].startingNode = 3;
    graph->arrayEdges[0].endingNode = 2;
    graph->arrayEdges[0].weight = 2;

    bellmanFordSingleSourceShortestPath(graph, singleSourceNode, graph->cardinalityVertices, graph->cardinalityEdges);

    return 0;
}

void bellmanFordSingleSourceShortestPath(Graph *graph, int singleSourceNode, int cardinalityVertices, int cardinalityEdges) {

    int i, j;
    int startingNodeChosenEdge, endingNodeChosenEdge, weightChosenEdge;

    int distanceArray[4]={INFINITY};

    distanceArray[singleSourceNode] = 0;

    for (i = 1; i <= graph->cardinalityVertices - 1; i++) {

        for (j = 0; j < graph->cardinalityEdges; j++) {

            startingNodeChosenEdge = graph->arrayEdges[j].startingNode;
            endingNodeChosenEdge = graph->arrayEdges[j].endingNode;
            weightChosenEdge = graph->arrayEdges[j].weight;

            if (distanceArray[startingNodeChosenEdge] != INFINITY &&
                distanceArray[endingNodeChosenEdge] > distanceArray[startingNodeChosenEdge] + weightChosenEdge) {

                distanceArray[endingNodeChosenEdge] = distanceArray[startingNodeChosenEdge] + weightChosenEdge;
            }
        }
    }

    for (i = 0; i < cardinalityEdges; i++) {

        startingNodeChosenEdge = graph->arrayEdges[i].startingNode;
        endingNodeChosenEdge = graph->arrayEdges[i].endingNode;
        weightChosenEdge = graph->arrayEdges[i].weight;

        if (distanceArray[startingNodeChosenEdge] != INFINITY
            && distanceArray[endingNodeChosenEdge] > distanceArray[startingNodeChosenEdge] + weightChosenEdge) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    printf("Bellman Ford Distance Array: ");

    for (int i = 0; i < cardinalityVertices; i++) {
        printf("%d, ", distanceArray[i]);
    }
}