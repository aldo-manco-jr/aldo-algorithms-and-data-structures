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
    int size;
} List;

List *createInstanceList();

void push(List *list, int integer);

int pop(List *list);

int peek(List *list);

boolean isEmpty(List *list);

int main() {
    List *list = createInstanceList();
    push(list, 3);
    push(list, 5);
    push(list, 4);
    push(list, 7);
    pushBack(list, 1);

    printList(list);

    pop(list);
    pop(list);
//    popBack(list);

    printList(list);

    reverseList(list);

    printList(list);

    printf("%i", peek(list));
    return 0;
}

List *createInstanceList() {
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

boolean isEmpty(List *list) {
    return list->size == 0 ? true : false;
}

void push(List *list, int integer) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void pushBack(List *list, int integer) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = integer;
    newNode->next = NULL;

    Node *currentNode = list->head;
    while (currentNode != NULL && currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    if (currentNode == NULL)
        list->head = newNode;
    else
        currentNode->next = newNode;
    list->size++;
}

int pop(List *list) {
    if (isEmpty(list) == true) return NULL;
    int removedValue = list->head->value;
    Node *removedNode = list->head;
    list->head = list->head->next;
    free(removedNode);
    list->size--;
    return removedValue;
}

/*int popBack(List *list) {
    if (isEmpty(list) == true) return NULL;

    if (list->head->next == NULL) {
        int removedValue = list->head->value;
        free(list->head);
        list->head = NULL;
        list->size--;
        return removedValue;
    }

    Node *currentNode = list->head;
    while (currentNode->next->next != NULL) {
        currentNode = currentNode->next;
    }

    int removedValue = currentNode->next->value;
    free(currentNode->next);
    currentNode->next = NULL;
    list->size--;
    return removedValue;
}*/

int peek(List *list) {
    if (isEmpty(list) == true) return NULL;
    int soughtValue = list->head->value;
    return soughtValue;
}

void reverseList(List *list) {

    Node *previous = NULL,
            *current = list->head,
            *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    list->head = previous;
}

void printList(List *list) {
    if (isEmpty(list) == true) {
        printf("%s", "Empty List");
        puts("");
        return;
    }
    Node *currentNode = list->head;
    while (currentNode != NULL) {
        printf("%i ", currentNode->value);
        currentNode = currentNode->next;
    }
    puts("");
}