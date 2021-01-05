#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} boolean;

typedef struct {
    int *heap;
    int size;
} Heap;

boolean isFull(Heap *heap);

boolean isEmpty(Heap *heap);

int getParent(int index);

int getChild(int index, boolean isLeft);

void insert(Heap *heap, int value);

void delete(Heap *heap, int index);

void heapSort(Heap *heap);

void fixHeapAbove(Heap *heap, int indexNewValue);

void fixHeapBelow(Heap *heap, int index, int lastHeapIndex);

void printHeap(Heap *heap);

int peek(Heap *heap);

int main() {

    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->heap = (int*) malloc(sizeof(int)*10);

    for (int i = 0; i < 10; ++i) {
        heap->heap[i]=0;
    }
    heap->size = 0;

    insert(heap, 9); //9 8 3 6 1
    insert(heap, 6);
    insert(heap, 3);
    insert(heap, 8);
    insert(heap, 1);

    //printHeap(heap);

    delete(heap, 0);

    //printHeap(heap);
    printf("\n%i\n", peek(heap));

    heapSort(heap);

    printHeap(heap);

    return 0;
}

boolean isFull(Heap *heap) {
    return (heap->size == 10) ? true : false;

}

boolean isEmpty(Heap *heap) {
    return (heap->size == 0) ? true : false;
}

void insert(Heap *heap, int value) {
    if (isFull(heap) == true) {
        perror("Heap is Full");
    }

    heap->heap[heap->size++] = value;
    //printf("\n%i", heap->size);

    fixHeapAbove(heap, heap->size - 1);
}

void delete(Heap *heap, int index) {
    if (isEmpty(heap) == true) {
        perror("Heap is Empty");
    }

    heap->heap[index] = heap->heap[heap->size - 1];
    heap->size--;

    if (index == 0 || heap->heap[index] < heap->heap[getParent(index)]) {
        fixHeapBelow(heap, index, heap->size-1);
    } else{
        fixHeapAbove(heap, index);
    }
}

void fixHeapAbove(Heap *heap, int indexNewValue) {

    int newValue = heap->heap[indexNewValue];

    while (indexNewValue > 0 && newValue > heap->heap[getParent(indexNewValue)]) {
        heap->heap[indexNewValue] = heap->heap[getParent(indexNewValue)];
        indexNewValue = getParent(indexNewValue);
    }
    heap->heap[indexNewValue] = newValue;
}

void fixHeapBelow(Heap *heap, int index, int lastHeapIndex){
    int childToSwap;

    while (index<=lastHeapIndex){
        int leftChildIndex = getChild(index, true);
        int rightChildIndex = getChild(index, false);

        if (leftChildIndex<=lastHeapIndex){
            if (rightChildIndex>lastHeapIndex){
                childToSwap = leftChildIndex;
            } else{
                childToSwap = heap->heap[leftChildIndex] > heap->heap[rightChildIndex] ? leftChildIndex : rightChildIndex;
            }

            if (heap->heap[childToSwap] > heap->heap[index]){
                int temp = heap->heap[childToSwap];
                heap->heap[childToSwap] = heap->heap[index];
                heap->heap[index] = temp;
            } else{
                break;
            }
            index = childToSwap;
        } else{
            break;
        }
    }
}

void heapSort(Heap *heap){

    int lastUnsortedIndex = heap->size-1;

    while (lastUnsortedIndex>0){
        int temp = heap->heap[0];
        heap->heap[0] = heap->heap[lastUnsortedIndex];
        heap->heap[lastUnsortedIndex] = temp;

        fixHeapBelow(heap, 0, --lastUnsortedIndex);
    }
}

int getParent(int index) {
    return (index - 1) / 2;
}

int getChild(int index, boolean isLeft) {
    return isLeft == true ? (2 * index) + 1 : (2 * index) + 2;
}

void printHeap(Heap *heap){
    for (int i = 0; i < heap->size; ++i) {
        printf("%i, ", heap->heap[i]);
    }
}

int peek(Heap *heap){
    return heap->heap[0];
}