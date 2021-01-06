#include <stdio.h>

/*
 * Created by Aldo Manco
 */

int main() {

    int array[] = {7, 1, -22, 55, 35, -15, 20};

    for (int j = sizeof(array) / 4 - 1; j > 0; --j) {

        int indexLargest = 0;

        for (int i = 1; i <= j; ++i) {
            if (array[i] > array[indexLargest]) {
                indexLargest = i;
            }
        }
        swap(array, indexLargest, j);
    }

    for (int i = 0; i < sizeof(array) / 4; ++i) {
        printf("%i\n", array[i]);
    }
    return 0;
}

void swap(int *array, int x, int y) {
    if (x == y) return;

    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}