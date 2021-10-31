#include <stdio.h>

#define INF 1073741823
#define CARDINALITY 8

void dijkstraSingleSourceShortestPath(int graph[CARDINALITY + 1][CARDINALITY + 1], int n, int start);

int main() {

    int graph[CARDINALITY + 1][CARDINALITY + 1] =
            {{INF, INF, INF, INF, INF, INF, INF, INF},
             {INF, INF, 7,   3,   4,   INF, 7,   INF},
             {INF, 9,   INF, 3,   INF, INF, INF, INF},
             {INF, 9,   6,   INF, 4,   4,   INF, INF},
             {INF, 7,   INF, 6,   INF, 5,   INF, INF},
             {INF, INF, INF, 4,   5,   INF, 9, 8},
             {INF, INF, INF, INF, INF, 6,   INF, INF},
             {INF, INF, INF, INF, INF, 9,   INF, INF}};

    int singleSourceNode = 1;

    dijkstraSingleSourceShortestPath(graph, CARDINALITY, singleSourceNode);

    return 0;
}

void dijkstraSingleSourceShortestPath(int graph[CARDINALITY + 1][CARDINALITY + 1], int n, int start) {

    int distancesArray[CARDINALITY + 1] = {INF};
    int optimalFoundArray[CARDINALITY + 1] = {0};
    int minDistance = INF;
    int nextNode;
    int i;

    for (i = 1; i < n; i++) {
        distancesArray[i] = graph[start][i];
    }

    distancesArray[start] = 0;
    optimalFoundArray[start] = 1;

    for (int k = 1; k <= n - 1; k++) {

        minDistance = INF;

        for (i = 1; i < n; i++) {

            if (distancesArray[i] < minDistance && optimalFoundArray[i]==0) {
                minDistance = distancesArray[i];
                nextNode = i;
            }
        }

        optimalFoundArray[nextNode] = 1;

        for (i = 1; i < n; i++) {

            if (optimalFoundArray[i]==0) {

                if (minDistance + graph[nextNode][i] < distancesArray[i]) {
                    distancesArray[i] = minDistance + graph[nextNode][i];
                }
            }
        }
    }

    for (i = 1; i < n; i++) {

        if (i != start) {
            printf("\nDistance from source to %d: %d", i, distancesArray[i]);
        }
    }
}