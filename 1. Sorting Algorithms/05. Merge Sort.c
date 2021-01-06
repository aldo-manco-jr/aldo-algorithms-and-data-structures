#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

int main() {
    int *intArray = calloc(7, sizeof(int));
    *(intArray) = 20;
    *(intArray + 1) = 35;
    *(intArray + 2) = -15;
    *(intArray + 3) = 7;
    *(intArray + 4) = 55;
    *(intArray + 5) = 1;
    *(intArray + 6) = -22;

    mergeSort(intArray, 0, 6);

    for (int i = 0; i < 7; ++i) {
        printf("%i\n", intArray[i]);
    }
    return 0;
}

void mergeSort(int *intArray, int start, int end) {
    if (end == start) return;

    int middle = (start + end) / 2;

    mergeSort(intArray, start, middle);
    mergeSort(intArray, middle + 1, end);
    merge(intArray, start, end);
}

void merge(int *intArray, int start, int end) {

    int middle = (start + end) / 2;

    int
            i = start,
            j = middle + 1,
            tmpIndex = 0;

    int tmpArray[end - start + 1];

    while (i <= middle && j <= end) {
        if (intArray[i] < intArray[j]){
            tmpArray[tmpIndex++] = intArray[i++];
        } else{
            tmpArray[tmpIndex++] = intArray[j++];
        }
    }

    while (i <= middle) {
        tmpArray[tmpIndex++] = intArray[i++];
    }
    while (j <= end) {
        tmpArray[tmpIndex++] = intArray[j++];
    }

    for (int k = 0; k < tmpIndex; ++k) {
        intArray[start + k] = tmpArray[k];
    }
}