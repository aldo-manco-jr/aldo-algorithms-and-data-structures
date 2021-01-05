#include <stdio.h>
#include <stdlib.h>

#define DIM 9

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
} boolean;

void countingSort(int *array, int min, int max, int size);

int main() {
    int *intArray = calloc(DIM, sizeof(int));
    *(intArray) = 2;
    *(intArray + 1) = 3;
    *(intArray + 2) = 5;
    *(intArray + 3) = 7;
    *(intArray + 4) = 5;
    *(intArray + 5) = 1;
    *(intArray + 6) = 2;
    *(intArray + 7) = 8;

    countingSort(intArray, getMinMax(intArray, 0, DIM-1, true), getMinMax(intArray, 0, DIM-1, false), DIM - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < DIM - 1; ++i) {
        printf("%i, ", intArray[i]);
    }
    return 0;
}

int getMinMax(int *array, int start, int end, boolean wantMin) {

    int max = array[start], min = array[start];

    for (int i = start + 1; i < end; ++i) {
        if (array[i] > max) {
            max = array[i];
        } else if (array[i] < min) {
            min = array[i];
        }
    }
    if (wantMin == true) return min;
    else return max;
}

void countingSort(int *array, int min, int max, int size) {
    int *occurrences = calloc((max - min) + 1, sizeof(int));

    for (int i = 0; i < (max - min) + 1; ++i) {
        occurrences[array[i] - min]++;
    }

    for (int i = 1; i < (max - min) + 1; ++i) {
        occurrences[i] = occurrences[i] + occurrences[i - 1];
    }

    int *tmp = calloc(size, sizeof(int));

    for (int i = size - 1; i >= 0; --i) {
        tmp[--occurrences[array[i] - min]] = array[i];
    }

    for (int i = 0; i < size; ++i) {
        array[i] = tmp[i];
    }
}