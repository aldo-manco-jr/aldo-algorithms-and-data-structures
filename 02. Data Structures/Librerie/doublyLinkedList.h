#ifndef GRAPHBFS_DFS_QUEUE_H
#define GRAPHBFS_DFS_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

/*
 * Created by Aldo Manco
 */

typedef struct {
    int value;
    struct Node *next;
    struct Node *previous;
} *head = NULL, *tail = NULL;

boolean isEmpty() {
    return head == NULL;
}

void pushFront(int integer) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = head;
    if (isEmpty()) tail = newNode;
    head = newNode;
}

void pushBack(int integer) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = NULL;
    newNode->previous = tail;
    tail->next = newNode;
    if (isEmpty()) head = newNode;
    tail = newNode;
}

int popFront(){
    if (isEmpty()) return NULL;

    int removedValue = head->value;
    Node *removedNode = head;

    if (head == tail){
        head = NULL;
        tail = NULL;
        free(removedNode);
        return removedValue;
    }

    head = head->next;
    head->previous = NULL;
    removedNode->next = NULL;
    free(removedNode);
    return removedValue;
}

int popBack(){
    if (isEmpty()) return NULL;

    if (head == tail) {
        int removedValue = head->value;
        Node *removedNode = head;
        head = NULL;
        tail = NULL;
        free(removedNode);
        return removedValue;
    }

    int removedValue = tail->value;
    Node *removedNode = tail;
    tail = tail->previous;
    tail->next = NULL;
    removedNode->previous = NULL;
    free(removedNode);
    return removedValue;
}

#endif //GRAPHBFS_DFS_QUEUE_H