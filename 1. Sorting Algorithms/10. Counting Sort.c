#include <stdio.h>
#include <stdlib.h>

#define DIM 8

/*
 * Created by Aldo Manco
 */

typedef enum {
    false, true
}boolean;

void countingSort(int *array, int min, int max);

int main() {
    int *intArray = calloc(DIM, sizeof(int));
    *(intArray) = 2;
    *(intArray + 1) = 3;
    *(intArray + 2) = 5;
    *(intArray + 3) = 7;
    *(intArray + 4) = 5;
    *(intArray + 5) = 1;
    *(intArray + 6) = 2;

    countingSort(intArray, getMinMax(intArray, 0, DIM, true), getMinMax(intArray, 0, DIM, false));

    for (int i = 1; i < DIM; ++i) {
        printf("%i\n", intArray[i]);
    }
    return 0;
}

int getMinMax(int *array, int start, int end, boolean wantMin){

    int max=array[start], min=array[start];

    for (int i = start+1; i < end; ++i) {
        if (array[i]>max){
            max=array[i];
        } else if (array[i]<min){
            min=array[i];
        }
    }
    if (wantMin==true) return min;
    else return max;
}

void countingSort(int *array, int min, int max){
    int *occurrences = calloc((max-min)+1, sizeof(int));

    for (int i = 0; i < (max-min)+1; ++i) {
        occurrences[array[i]-min]++;
    }

    int j=0;
    for (int i = min; i <= max; ++i) {
        while (occurrences[i-min]>0){
            array[j++] = i;
            occurrences[i-min]--;
        }
    }
}