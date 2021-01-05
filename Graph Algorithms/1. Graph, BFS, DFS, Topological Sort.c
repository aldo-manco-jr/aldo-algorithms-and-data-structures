#include <stdio.h>
#include "queue.h"

/*
 * Created by Aldo Manco
 */

void breadthFirstSearch(int graph[][8], int start, int n);

void depthFirstSearch(int graph[][8], int start, int n);

int topologicalSortArray[8];
int counter = 8;

int main() {
    int graph[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 1, 1, 0, 0},
                       {0, 1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0}};

    puts("Breadth First Search: ");
    breadthFirstSearch(graph, 1, 8);
    puts("\n");
    puts("Depth First Search: ");
    depthFirstSearch(graph, 1, 8);
    puts("\n");
    puts("Topological Sort: ");
    topologicalSort(graph,1,8);

    for (int i = 1; i < 8; ++i) {
        printf("%i, ", topologicalSortArray[i]);
    }

    return 0;
}

void breadthFirstSearch(int graph[][8], int start, int n) {

    int i = start, j;
    int visited[8] = {0};

    printf("%i, ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {

        i = dequeue();

        for (j = 1; j < n; ++j) {
            if (graph[i][j] == 1 && visited[j] == 0) {
                printf("%i, ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

}

void depthFirstSearch(int graph[][8], int start, int n) {

    int j;
    static int visited[8] = {0};

    if (visited[start] == 0){
        printf("%i, ", start);
        visited[start]=1;

        for (j = 1; j < n; j++) {
            if (graph[start][j] == 1 && visited[j]==0){
                depthFirstSearch(graph, j, n);
            }
        }
    }
}

void topologicalSort(int graph[][8], int start, int n){
    int j;
    static int visited[8] = {0};

    if (visited[start] == 0){
        topologicalSortArray[--counter] = start;
        visited[start]=1;

        for (j = 1; j < n; j++) {
            if (graph[start][j] == 1 && visited[j]==0){
                topologicalSort(graph, j, n);
            }
        }
    }
}