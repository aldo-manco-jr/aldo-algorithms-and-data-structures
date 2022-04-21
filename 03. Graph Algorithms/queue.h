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
} *head = NULL, *tail = NULL;

typedef struct Node Node;

void enqueue(int value) {

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty()) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}

int dequeue() {

    if (isEmpty()) {
        perror("Queue is Empty");
        return 0;
    }

    Node *removedNode = head;
    int removedValue = head->value;

    if (head == tail) {
        head = NULL;
        tail = NULL;
        free(removedNode);
        return removedValue;
    }

    head = head->next;
    free(removedNode);
    return removedValue;
}

int isEmpty() {
    return head == NULL;
}

#endif //GRAPHBFS_DFS_QUEUE_H