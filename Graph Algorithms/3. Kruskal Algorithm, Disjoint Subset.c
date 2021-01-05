#include <stdio.h>

#define NUMBER_VERTICES 7
#define NUMBER_EDGES 9
#define INFINITE 2147483647

/*
 * Created by Aldo Manco
 */

void join(int u, int v);

int find(int u);

int disjointSubset[NUMBER_VERTICES + 1];

int main() {

    int graph[NUMBER_EDGES + 1][3] =
            {{1, 2, 28},
             {1, 6, 10},
             {2, 3, 16},
             {2, 7, 14},
             {3, 4, 12},
             {4, 5, 22},
             {4, 7, 18},
             {5, 6, 25},
             {5, 7, 24}
            };

    int shortestPathVertices[NUMBER_VERTICES][2];

    int checkedEdges[NUMBER_EDGES + 1];

    for (int i = 0; i < NUMBER_VERTICES; ++i) {
        disjointSubset[i] = -1;
    }

    for (int j = 0; j < NUMBER_EDGES; ++j) {
        checkedEdges[j] = 0;
    }

    int numberOfChosenEdges = 0, currentChosenEdges = 0, minimumCost;
    int startingNode = 0, endingNode = 0;

    while (numberOfChosenEdges < NUMBER_VERTICES - 1) {

        minimumCost = INFINITE;

        for (int i = 0; i < NUMBER_EDGES; ++i) {

            if (checkedEdges[i] == 0
                && graph[i][2] < minimumCost) {

                startingNode = graph[i][0];
                endingNode = graph[i][1];
                minimumCost = graph[i][2];
                currentChosenEdges = i;
            }
        }

        if (find(startingNode) != find(endingNode)) {

            shortestPathVertices[numberOfChosenEdges][0] = startingNode;
            shortestPathVertices[numberOfChosenEdges][1] = endingNode;

            join(find(startingNode), find(endingNode));

            checkedEdges[currentChosenEdges] = 1;
            numberOfChosenEdges++;

        } else {
            checkedEdges[currentChosenEdges] = 1;
        }
    }

    printf("Spanning Tree:\n");

    for (int k = 0; k < NUMBER_VERTICES-1; ++k) {
        printf("(%i -> %i)\n", shortestPathVertices[k][0], shortestPathVertices[k][1]);
    }

    return 0;
}

void join(int u, int v) {

    if (disjointSubset[u] < disjointSubset[v]) {
        disjointSubset[u] += disjointSubset[v];
        disjointSubset[v] = u;
    } else {
        disjointSubset[v] += disjointSubset[u];
        disjointSubset[u] = v;
    }
}

int find(int u) {

    int currentVertice = u;
    while (disjointSubset[currentVertice] > 0) {
        currentVertice = disjointSubset[currentVertice];
    }

    return currentVertice;
}