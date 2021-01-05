#include <stdio.h>

/*
 * Created by Aldo Manco
 */

int main() {

    int array[] = {7, 1, -22, 55, 35, -15, 20};

    for (int i = 1; i < sizeof(array) / 4; ++i) {
        int newElement = array[i];
        int j;

        for (j = i; j > 0 && newElement < array[j - 1]; --j) {
            array[j] = array[j-1];
        }

        array[j] = newElement;
    }

    for (int i = 0; i < sizeof(array) / 4; ++i) {
        printf("%i\n", array[i]);
    }

    return 0;
}