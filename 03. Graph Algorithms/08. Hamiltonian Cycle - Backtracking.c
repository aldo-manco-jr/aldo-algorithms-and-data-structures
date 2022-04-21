#include <stdio.h>
#include <stdlib.h>

#define VERTICES 5

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} Boolean;

void printSolution(int hamiltonianPath[]);

Boolean canBeChosen(int currentVertex, Boolean graph[VERTICES][VERTICES], int hamiltonianPath[], int toFillPosition);

Boolean hamiltonianCycle(Boolean graph[VERTICES][VERTICES], int hamiltonianPath[], int toFillPosition);

int main() {

    Boolean graph[VERTICES][VERTICES] = {{false, true,  false, true,  false},
                                         {true,  false, true,  true,  true},
                                         {false, true,  false, false, true},
                                         {true,  true,  false, false, true},
                                         {false, true,  true,  true,  false},
    };

    int *hamiltonianPath = (int *) calloc(VERTICES, sizeof(int));

    for (int i = 0; i < VERTICES; ++i) {
        hamiltonianPath[i] = -1;
    }

    hamiltonianPath[0] = 0;

    if (hamiltonianCycle(graph, hamiltonianPath, 1) == false) {
        puts("It doesn't exist any Hamiltonian Cycle in the Graph");
    }

    puts("First Hamiltonian Cycle Found:");
    printSolution(hamiltonianPath);

    return 0;
}

Boolean canBeChosen(int currentVertex, Boolean graph[VERTICES][VERTICES], int hamiltonianPath[], int toFillPosition) {

    if (graph[hamiltonianPath[toFillPosition - 1]][currentVertex] == false) {
        return false;
    }

    for (int i = 0; i < toFillPosition; ++i) {

        if (hamiltonianPath[i] == currentVertex) {
            return false;
        }
    }

    return true;
}

Boolean hamiltonianCycle(Boolean graph[VERTICES][VERTICES], int hamiltonianPath[], int toFillPosition) {

    if (toFillPosition == VERTICES) {

        if (graph[hamiltonianPath[toFillPosition-1]][hamiltonianPath[0]] == true) {
            return true;
        } else {
            return false;
        }
    }

    for (int i = 1; i < VERTICES; ++i) {

        if (canBeChosen(i, graph, hamiltonianPath, toFillPosition) == true) {

            hamiltonianPath[toFillPosition] = i;

            if (hamiltonianCycle(graph, hamiltonianPath, toFillPosition+1) == true) {
                return true;
            }

            hamiltonianPath[toFillPosition] = -1;
        }
    }

    return false;
}

void printSolution(int hamiltonianPath[]) {

    printf("Solution Exists:\n");

    for (int i = 0; i < VERTICES; i++) {
        printf("%d, ", hamiltonianPath[i]);
    }

    printf("%d", hamiltonianPath[0]);
}