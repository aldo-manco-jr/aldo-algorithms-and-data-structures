#ifndef GRAPHBFS_DFS_QUEUE_H
#define GRAPHBFS_DFS_QUEUE_H

#include <stdlib.h>
#include <stdio.h>

/*
 * Created by Aldo Manco
 */

struct Node{
    int value;
    struct Node *next;
} *head = NULL;

typedef struct Node Node;

void push(int integer) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = head;
    head = newNode;
}

int pop() {
    if (isEmpty()) return NULL;
    int removedValue = head->value;
    Node *removedNode = head;
    head = head->next;
    free(removedNode);
    return removedValue;
}

int peek() {
    if (isEmpty()) return NULL;
    return head->value;
}

int isEmpty() {
    return head == NULL;
}

#endif //GRAPHBFS_DFS_QUEUE_H