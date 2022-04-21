#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define CARDINALITY 7
#define MINUS_INFINITE -2147483648

struct Node {
    int value;
    struct Node *next;
    struct Node *previous;
};

typedef struct Node Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;

List *createInstanceList();

bool isEmpty(List *list);

void enqueue(List *list, int integer);

int dequeue(List *list);

void printList(List *list);

bool isTricolored(int graph[][8], List *queue, int start, int n);

int generateNonDeterministicValue();

int main() {

    int graph[CARDINALITY+1][CARDINALITY+1] =
                      {{0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 1, 1, 0, 0},
                       {0, 1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0}};

    List *list = createInstanceList();

    assert(!isTricolored(graph, list, 1, CARDINALITY+1));

    return 0;
}

List *createInstanceList() {

    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

bool isEmpty(List *list) {
    return list->size == 0;
}

void enqueue(List *list, int integer) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = NULL;
    newNode->previous = list->tail;

    if (!isEmpty(list)) {
        list->tail->next = newNode;
    }

    if (isEmpty(list)) {
        list->head = newNode;
    }

    list->tail = newNode;
    list->size++;
}

int dequeue(List *list) {

    if (isEmpty(list)) {
        return MINUS_INFINITE;
    }

    int removedValue = list->head->value;
    Node *removedNode = list->head;

    list->size--;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        free(removedNode);
        return removedValue;
    }

    list->head = list->head->next;
    list->head->previous = NULL;
    removedNode->next = NULL;
    free(removedNode);

    return removedValue;
}

void printList(List *list) {

    Node *currentNode = list->head;

    while (currentNode != NULL) {
        printf("%i", currentNode->value);
        currentNode = currentNode->next;
    }
}

bool isTricolored(int graph[][8], List *queue, int start, int n) {

    int i = start, j;
    int visited[8] = {0};
    int color[8] = {0, 0, 1, 2, 3, 1, 2, 2};

    /*int color[8] = {MINUS_INFINITE};

    for (int k=0; k<n; k++){
        color[k]=generateNonDeterministicValue();
        __VERIFIER_assume(color[k]>=0 && color[k]<=2);
    }*/

    printf("%i, ", i);
    visited[i] = 1;
    enqueue(queue, i);

    while (!isEmpty(queue)) {

        i = dequeue(queue);

        for (j = 1; j < n; ++j) {
            if (graph[i][j] == 1 && visited[j] == 0) {
                printf("%i, ", j);
                visited[j] = 1;
                enqueue(queue, j);
            }
            if (graph[i][j] == 1 && color[j] == color[i]) {
                return false;
            }
        }
    }
    return true;
}