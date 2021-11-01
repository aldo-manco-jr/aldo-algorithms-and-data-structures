#include <stdio.h>
#include <stdlib.h>

#define VERTICES 5

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} Boolean;

void printSolution(int path[]);

Boolean canBeChosen(int currentVertex, Boolean graph[VERTICES][VERTICES], int path[], int toFillPosition);

Boolean hamiltonianCycle(Boolean graph[VERTICES][VERTICES], int path[], int toFillPosition);

int main() {

    Boolean graph[VERTICES][VERTICES] = {{false, true,  false, true,  false},
                                         {true,  false, true,  true,  true},
                                         {false, true,  false, false, true},
                                         {true,  true,  false, false, true},
                                         {false, true,  true,  true,  false},
    };

    int *path = (int *) calloc(VERTICES, sizeof(int));

    for (int i = 0; i < VERTICES; ++i) {
        path[i] = -1;
    }

    path[0] = 0;

    if (hamiltonianCycle(graph, path, 1) == false) {
        puts("It doesn't exist any Hamiltonian Cycle in the Graph");
    }

    puts("First Hamiltonian Cycle Found:");
    printSolution(path);

    return 0;
}

Boolean canBeChosen(int currentVertex, Boolean graph[VERTICES][VERTICES], int path[], int toFillPosition) {

    if (graph[path[toFillPosition - 1]][currentVertex] == false) {
        return false;
    }

    for (int i = 0; i < toFillPosition; ++i) {

        if (path[i] == currentVertex) {
            return false;
        }
    }

    return true;
}

Boolean hamiltonianCycle(Boolean graph[VERTICES][VERTICES], int path[], int toFillPosition) {

    if (toFillPosition == VERTICES) {

        if (graph[path[toFillPosition-1]][path[0]] == true) {
            return true;
        } else {
            return false;
        }
    }

    for (int i = 1; i < VERTICES; ++i) {

        if (canBeChosen(i, graph, path, toFillPosition) == true) {

            path[toFillPosition] = i;

            if (hamiltonianCycle(graph, path, toFillPosition+1) == true) {
                return true;
            }

            path[toFillPosition] = -1;
        }
    }

    return false;
}

void printSolution(int path[]) {

    printf("Solution Exists:\n");

    for (int i = 0; i < VERTICES; i++) {
        printf("%d, ", path[i]);
    }

    printf("%d", path[0]);
}