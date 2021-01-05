#include <stdio.h>

/*
 * Created by Aldo Manco
 */

typedef enum{
    false, true
}boolean;

int main() {
    int unsortedArray[8] = {20, 35, -15, 7, 55, 1, -22};

    boolean hasSwapped = true;
    int lastUnsortedIndex = 7;

    while(hasSwapped==true) {
        hasSwapped = false;
        for (int i = 0; i < lastUnsortedIndex-1; ++i) {
            if (unsortedArray[i]>unsortedArray[i+1]){
                swap(unsortedArray, i, i+1);
                hasSwapped = true;
            }
        }
        lastUnsortedIndex--;
    }

    printf("Sorted Array: ");
    for (int j = 0; j < 7; ++j) {
        printf("%i, ", unsortedArray[j]);
    }

    return 0;
}

void swap(int *array, int i, int j){
    if(i==j) return;

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}