#ifndef GRAPHBFS_DFS_QUEUE_H
#define GRAPHBFS_DFS_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

struct Node{
    int value;
    struct Node *next;
} *top;

typedef struct Node Node;

void push(int newValue){

    Node *newNode = malloc(sizeof(Node*));
    newNode->value = newValue;
    newNode->next = top;
    top = newNode;
}

int pop(){

    if (isEmpty()) return NULL;
    Node *removedNode = top;
    int removedValue = removedNode->value;
    top = top->next;
    free(removedNode);
    return removedValue;
}

int peek(){
    if(isEmpty()) return NULL;
    return top->value;
}

int isEmpty(){
    return top == NULL;
}

#endif //GRAPHBFS_DFS_QUEUE_H