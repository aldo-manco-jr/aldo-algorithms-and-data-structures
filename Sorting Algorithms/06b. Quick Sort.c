#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

void quickSort(int *array, int start, int end);

int partition(int *array, int start, int end);

int main() {
    int *intArray = calloc(7, sizeof(int));
    *(intArray) = 20;
    *(intArray + 1) = 35;
    *(intArray + 2) = -15;
    *(intArray + 3) = 7;
    *(intArray + 4) = 55;
    *(intArray + 5) = 1;
    *(intArray + 6) = -22;

    quickSort(intArray, 0, 7);

    for (int i = 0; i < 7; ++i) {
        printf("%i\n", intArray[i]);
    }
    return 0;
}

void quickSort(int *array, int start, int end) {
    if (end - start < 2) return;

    int pivotIndex = partition(array, start, end);
    quickSort(array, start, pivotIndex);
    quickSort(array, pivotIndex + 1, end);
}

int partition(int *array, int start, int end) {

    int pivot = array[start];
    int i = start;
    int j = end;

    while (i < j) {
        while (i < j && array[--j] >= pivot);
        if (i < j) {
            array[i] = array[j];
        }

        while (i < j && array[++i] <= pivot);
        if (i < j) {
            array[j] = array[i];
        }
    }
    array[j] = pivot;
    return j;
}