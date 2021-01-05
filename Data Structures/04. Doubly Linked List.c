#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} boolean;

typedef struct {
    int value;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;

int main() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    pushFront(list, 3); //35829
    pushFront(list, 9);
    pushFront(list, 1);
    pushFront(list, 7);

    pushBack(list, 5);
    pushBack(list, 8);
    pushBack(list, 2);

    pushBack(list, 9);
    pushBack(list, 3);
    pushBack(list, 1);

    popFront(list);
    popFront(list);
    popFront(list);

    popBack(list);
    popBack(list);

    printList(list);

    return 0;
}

List *createInstanceList() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

boolean isEmpty(List *list) {
    return list->size == 0;
}

void pushFront(List *list, int integer) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = list->head;
    if (isEmpty(list) == true) list->tail = newNode;
    list->head = newNode;
    list->size++;
}

void pushBack(List *list, int integer) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = NULL;
    newNode->previous = list->tail;
    list->tail->next = newNode;
    if (isEmpty(list) == true) list->head = newNode;
    list->tail = newNode;
    list->size++;
}

int popFront(List *list){
    if (isEmpty(list) == true) return NULL;

    int removedValue = list->head->value;
    Node *removedNode = list->head;

    if (list->head == list->tail){
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

int popBack(List *list){
    if (isEmpty(list)==true) return NULL;

    if (list->head == list->tail) {
        int removedValue = list->head->value;
        Node *removedNode = list->head;
        list->head = NULL;
        list->tail = NULL;
        free(removedNode);
        return removedValue;
    }

    int removedValue = list->tail->value;
    Node *removedNode = list->tail;
    list->tail = list->tail->previous;
    list->tail->next = NULL;
    removedNode->previous = NULL;
    free(removedNode);
    return removedValue;
}

void printList(List *list){
    Node *currentNode = list->head;
    while (currentNode!=NULL){
        printf("%i", currentNode->value);
        currentNode = currentNode->next;
    }
}