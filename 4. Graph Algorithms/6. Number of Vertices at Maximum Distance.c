#include <stdio.h>
#include "queue.h"

#define INFINITE 2147483647

/*
 * Created by Aldo Manco
 */

int findNumberVerticesMaximumDistance(int graph[][8], int sourceVertex, int numberVerticesGraph);

int main() {

    int numberOfVertices = 7;

    int graph[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 1, 1, 0, 0},
                       {0, 1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0}};

    int numberVerticesMaximumDistances = findNumberVerticesMaximumDistance(graph, 1, numberOfVertices+1);
    printf("Number of Vertices at Maximum Distance: %d", numberVerticesMaximumDistances);

    return 0;
}

int findNumberVerticesMaximumDistance(int graph[][8], int sourceVertex, int numberVerticesGraph) {

    int i = sourceVertex;
    int j;
    int distances[numberVerticesGraph];

    for (int m = 0; m < numberVerticesGraph; ++m) {
        distances[m] = INFINITE;
    }

    distances[i] = 0;
    enqueue(i);

    while (!isEmpty()) {

        i = dequeue();

        for (j = 1; j < numberVerticesGraph; ++j) {
            if (graph[i][j] == 1 && distances[j] == INFINITE) {
                distances[j] = distances[i] + 1;
                enqueue(j);
            }
        }
    }

    int max = 0;

    for (int l = 1; l < numberVerticesGraph; l++){
        if (max < distances[l]){
            max = distances[l];
        }
        // printf("%d - ", distances[l]);
    }

    int counter = 0;

    for (int k = 1; k < numberVerticesGraph; k++) {
        if (max == distances[k]){
            counter++;
        }
    }

    return counter;
}