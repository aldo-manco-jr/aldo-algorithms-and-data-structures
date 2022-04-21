#include <stdio.h>

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} boolean;

void insert(int *array, int newValue);

int deleteHighestPriority(int *array);

int getHighestPriority(int *array);

void fixHeapBelow(int *array, int size, int i);

int getChild(int index, boolean isLeft);

void printArray(int *array, int size);

int size = 0;

int main() {
    int array[10];

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printArray(array, size);

    deleteHighestPriority(array);

    puts("");
    printArray(array, size);

    printf("\nPeek: %i", getHighestPriority(array));
    return 0;
}

void insert(int *array, int newValue) {

    if (size == 0) {
        array[0] = newValue;
        size++;
    } else {
        array[size] = newValue;
        size++;
        for (int i = size / 2 - 1; i >= 0; --i) {
            fixHeapBelow(array, size, i);
        }
    }
}

int deleteHighestPriority(int *array) {

    if (size==0){
        perror("Empty Priority Queue");
        return NULL;
    }

    int deletedValue = array[0];
    array[0] = array[size-1];
    size--;

    fixHeapBelow(array, size-1, 0);

    return deletedValue;
}

int getHighestPriority(int *array) {

    if (size == 0){
        perror("Empty Priority Queue");
        return NULL;
    }

    return array[0];
}

void printArray(int *array, int size) {
    printf("Heap: ");
    for (int i = 0; i < size; ++i) {
        printf("%i, ", array[i]);
    }
}

void fixHeapBelow(int *array, int lastHeapIndex, int index) {

    int childToSwap;

    while (index <= lastHeapIndex) {
        int leftChildIndex = getChild(index, true);
        int rightChildIndex = getChild(index, false);

        if (leftChildIndex <= lastHeapIndex) {
            if (rightChildIndex > lastHeapIndex) {
                childToSwap = leftChildIndex;
            } else {
                childToSwap = (array[leftChildIndex] > array[rightChildIndex]) ? leftChildIndex : rightChildIndex;
            }


            if (array[index] < array[childToSwap]) {
                int temp = array[childToSwap];
                array[childToSwap] = array[index];
                array[index] = temp;
            } else {
                break;
            }
        } else {
            break;
        }
        index = childToSwap;
    }
}

int getChild(int index, boolean isLeft) {
    return (isLeft == true) ? (2 * index) + 1 : (2 * index) + 2;
}