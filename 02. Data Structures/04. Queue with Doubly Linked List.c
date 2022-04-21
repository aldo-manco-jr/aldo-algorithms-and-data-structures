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
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

int peek(Queue *queue);

int size(Queue *queue);

void printQueue(Queue *queue);

int main() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 3);

    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 2);
    enqueue(queue, 4);

    printf("%i", size(queue));

    printQueue(queue);

    return 0;
}

/*Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}*/

int size(Queue *queue) {
    return queue->size;
}

void enqueue(Queue *queue, int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (size(queue) == 0){
        queue->head = newNode;
    } else{
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
    queue->size++;
}

int dequeue(Queue *queue){
    if (size(queue)==0){
        puts("Queue is Empty");
        return NULL;
    }

    int removedInteger = queue->head->value;
    Node *removedNode = queue->head;

    if (size(queue)==1){
        queue->head = NULL;
        queue->tail = NULL;
        free(removedNode);
        queue->size--;
        return removedInteger;
    }

    queue->head = removedNode->next;
    free(removedNode);
    queue->size--;
    return removedInteger;
}

int peek(Queue *queue){
    if (size(queue)==0) return NULL;
    return queue->head;
}

void printQueue(Queue *queue){
    Node *currentNode = queue->head;
    while (currentNode!=NULL){
        printf("%i\n", currentNode->value);
        currentNode = currentNode->next;
    }
}