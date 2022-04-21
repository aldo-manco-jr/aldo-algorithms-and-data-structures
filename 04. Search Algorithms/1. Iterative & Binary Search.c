#include <stdio.h>

/*
 * Created by Aldo Manco
 */

int main() {
    int array[] = {7, 1, -22, 55, 35, -15, 20};

    mergeSort(array, 0, sizeof(array) / 4);

    for (int i = 0; i < sizeof(array) / 4; i++) {
        printf("%i, ", array[i]);
    }

    puts("");
    puts("");
    printf("%i, ", iterativeBinarySearch(array, sizeof(array) / 4,-22));
    printf("%i, ", iterativeBinarySearch(array, sizeof(array) / 4, -15));
    printf("%i, ", iterativeBinarySearch(array, sizeof(array) / 4, 1));
    printf("%i, ", iterativeBinarySearch(array, sizeof(array) / 4, 7));

    puts("");

    printf("%i, ", recursiveBinarySearch(array, 0, sizeof(array)/4, 20));
    printf("%i, ", recursiveBinarySearch(array, 0, sizeof(array)/4, 35));
    printf("%i, ", recursiveBinarySearch(array, 0, sizeof(array)/4, 55));

    return 0;
}

int iterativeBinarySearch(int *array, int length, int element) {
    int start = 0, end = length, mid;

    while (start < end) {
        mid = (start + end) / 2;
        if (array[mid] < element) {
            start = mid + 1;
        } else if (array[mid] > element) {
            end = mid;
        } else if (array[mid] == element) {
            return mid;
        }
    }
    return -1;
}

int recursiveBinarySearch(int *array, int start, int end, int element) {
    if (start>=end) return -1;

    int middle = (start+end)/2;

    if (array[middle]<element){
        return recursiveBinarySearch(array, middle+1, end, element);
    } else if (array[middle]>element){
        return recursiveBinarySearch(array, start, middle, element);
    } else{
        return middle;
    }
}

void mergeSort(int *array, int start, int end) {
    if (end - start < 2) return;

    int middle = (end + start) / 2;

    mergeSort(array, start, middle);
    mergeSort(array, middle, end);
    merge(array, start, end);
}

void merge(int *array, int start, int end) {

    int middle = (end + start) / 2;
    int i = start, j = middle;
    int currentIndex = 0;
    int tmpArray[end - start];

    while (i < middle && j < end) {
        if (array[i] < array[j]) {
            tmpArray[currentIndex++] = array[i++];
        } else {
            tmpArray[currentIndex++] = array[j++];
        }
    }

    while (i < middle) {
        tmpArray[currentIndex++] = array[i++];
    }
    while (j < end) {
        tmpArray[currentIndex++] = array[j++];
    }

    for (int k = 0; k < currentIndex; ++k) {
        array[start + k] = tmpArray[k];
    }
}