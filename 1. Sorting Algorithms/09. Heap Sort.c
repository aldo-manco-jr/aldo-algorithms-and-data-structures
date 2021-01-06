#include <stdio.h>
#include <stdlib.h>

#define DIM 8

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} boolean;

int main() {
    int *intArray = calloc(DIM, sizeof(int));
    *(intArray) = 20;
    *(intArray + 1) = 35;
    *(intArray + 2) = -15;
    *(intArray + 3) = 7;
    *(intArray + 4) = 55;
    *(intArray + 5) = 1;
    *(intArray + 6) = -22;
    *(intArray + 7) = 22;

    heapSort(intArray, DIM-1);

    for (int i = 0; i < DIM; ++i) {
        printf("%i, ", intArray[i]);
    }

    return 0;
}

void heapSort(int *array, int size) {

    int lastUnsortedIndex = size;

    for (int i = size/2; i >=0; --i) {
        fixHeapBelow(array, i, size);
    }

    while (lastUnsortedIndex>0){
        int temp = array[0];
        array[0] = array[lastUnsortedIndex];
        array[lastUnsortedIndex] = temp;

        fixHeapBelow(array, 0, --lastUnsortedIndex);
    }
}

void fixHeapBelow(int *array, int index, int lastHeapIndex){
    int childToSwap;

    while (index<=lastHeapIndex){
        int leftChildIndex = getChild(index, true);
        int rightChildIndex = getChild(index, false);

        if (leftChildIndex<=lastHeapIndex){
            if (rightChildIndex>lastHeapIndex){
                childToSwap = leftChildIndex;
            } else{
                childToSwap = array[leftChildIndex] > array[rightChildIndex] ? leftChildIndex : rightChildIndex;
            }

            if (array[childToSwap] > array[index]){
                int temp = array[childToSwap];
                array[childToSwap] = array[index];
                array[index] = temp;
            } else{
                break;
            }
            index = childToSwap;
        } else{
            break;
        }
    }
}

int getChild(int parentIndex, boolean isLeft) {
    return (isLeft == true) ? (2 * parentIndex) + 1 : (2 * parentIndex) + 2;
}