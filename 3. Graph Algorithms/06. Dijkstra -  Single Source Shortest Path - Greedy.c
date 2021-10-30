#include <stdio.h>

#define INF 2147483647
#define CARDINALITY 8

void dijkstraSingleSourceShortestPath(int graph[CARDINALITY+1][CARDINALITY+1], int n, int start);

int main() {

    int graph[CARDINALITY+1][CARDINALITY+1] =
            {{INF, INF, INF, INF, INF, INF, INF, INF},
             {INF, INF, 7, 3, 4, INF, 7, INF},
             {INF, 9, INF, 3, INF, INF, INF, INF},
             {INF, 9, 6, INF, 4, 4, INF, INF},
             {INF, 7, INF, 6, INF, 5, INF, INF},
             {INF, INF, INF, 4, 5, INF, 9, 8},
             {INF, INF, INF, INF, INF, 6, INF, INF},
             {INF, INF, INF, INF, INF, 9, INF, INF}};

    int singleSourceNode = 1;

    dijkstraSingleSourceShortestPath(graph, CARDINALITY+1, singleSourceNode);

    return 0;
}

void dijkstraSingleSourceShortestPath(int graph[CARDINALITY+1][CARDINALITY+1], int n, int start) {

    int distancesArray[CARDINALITY+1] = {INF};
    int visitedArray[CARDINALITY+1] = {0};
    int count = 0;
    int minDistance = INF;
    int nextNode;
    int i;

    for (i = 1; i < n; i++) {
        distancesArray[i] = graph[start][i];
        count++;
    }

    distancesArray[start] = 0;
    visitedArray[start] = 1;

    while (count < n - 1) {

        minDistance = INF;

        for (i = 1; i < n; i++) {

            if (distancesArray[i] < minDistance && !visitedArray[i]) {
                minDistance = distancesArray[i];
                nextNode = i;
            }
        }

        visitedArray[nextNode] = 1;

        for (i = 1; i < n; i++) {

            if (!visitedArray[i]) {

                if (minDistance + graph[nextNode][i] < distancesArray[i]) {
                    distancesArray[i] = minDistance + graph[nextNode][i];
                }
            }
        }

        count++;
    }

    for (i = 1; i < n; i++) {

        if (i != start) {
            printf("\nDistance from source to %d: %d", i, distancesArray[i]);
        }
    }
}