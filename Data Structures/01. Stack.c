#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

typedef enum{
    false, true
}boolean;

typedef struct{
    int value;
    struct Node *next;
}Node;

typedef struct{
    int size;
    Node *top;
}Stack;

void push(Stack *stack, int newValue);
int pop(Stack *stack);
int peek(Stack *stack);
boolean isEmpty(Stack *stack);
void printStack(Stack *stack);

int main() {
    Stack *stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;

    push(stack, 9);
    push(stack, 9);
    push(stack, 8);
    push(stack, 3);
    push(stack, 10);

    pop(stack);
    pop(stack);

    printf("%i", peek(stack));
    puts("");
    printStack(stack);
    return 0;
}

void push(Stack *stack, int newValue){

    Node *newNode = malloc(sizeof(Node*));
    newNode->value = newValue;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack *stack){

    if (isEmpty(stack)==true) return NULL;
    Node *removedNode = stack->top;
    int removedValue = removedNode->value;
    stack->top = stack->top->next;
    free(removedNode);
    stack->size--;
    return removedValue;
}

int peek(Stack *stack){
    if(isEmpty(stack)==true) return NULL;
    return stack->top->value;
}

boolean isEmpty(Stack *stack){
    return (stack->size==0) ? true : false;
}

void printStack(Stack *stack){

    if (isEmpty(stack) == true) {
        printf("%s", "Empty Stack");
        puts("");
        return;
    }

    printf("Stack: ");

    Node *currentNode = stack->top;
    while (currentNode!=NULL){
        printf("%i, ", currentNode->value);
        currentNode = currentNode->next;
    }
}