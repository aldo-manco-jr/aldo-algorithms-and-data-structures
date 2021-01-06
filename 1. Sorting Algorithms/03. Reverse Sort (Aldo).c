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

    reverseSort(intArray, 0, 6);

    for (int i = 0; i < 7; ++i) {
        printf("%i\n", intArray[i]);
    }
    return 0;
}

void reverseSort(int *array, int start, int end) {

    for (int lastUnsortedIndex = end-start, firstUnsortedIndex = 0; lastUnsortedIndex>firstUnsortedIndex; --lastUnsortedIndex, ++firstUnsortedIndex) {
        int maximumIndex = firstUnsortedIndex;
        int minimumIndex = firstUnsortedIndex;

        for (int i = firstUnsortedIndex; i <= lastUnsortedIndex; ++i) {
            if (array[maximumIndex] < array[i]) {
                maximumIndex = i;
            } else if (array[minimumIndex] > array[i]) {
                minimumIndex = i;
            }
        }

        if (minimumIndex > maximumIndex){
            minimumIndex = end - (minimumIndex-maximumIndex);
            reverse(array, maximumIndex, lastUnsortedIndex);
            reverse(array, firstUnsortedIndex, minimumIndex);
        } else if (minimumIndex<maximumIndex){
            reverse(array, maximumIndex, lastUnsortedIndex);
            reverse(array, firstUnsortedIndex, minimumIndex);
        } else{
            break;
        }
    }
}

void reverse(int *array, int start, int end) {
    while (start < end) {
        swap(array, start++, end--);
    }
}

void swap(int *array, int i, int j) {
    if (i == j) return;

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}