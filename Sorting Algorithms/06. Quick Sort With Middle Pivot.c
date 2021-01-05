#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

void quickSort(int *array, int start, int end);

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
    if (start >= end) return;

    int pivot = array[(start + end) / 2];
    int i = start;
    int j = end;

    while (i <= j) {
        while (array[j] > pivot) j--;
        while (array[i] < pivot) i++;

        if (i <= j) {
            swap(array, i, j);
            i++;
            j--;
        }
    }
    if (j > start) quickSort(array, start, j);
    if (i < end) quickSort(array, i, end);
}

void swap(int *array, int i, int j) {
    if (i == j) return;

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}