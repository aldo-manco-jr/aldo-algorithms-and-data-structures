#include <stdio.h>

/*
 * Created by Aldo Manco
 */

int main() {

    int array[] = {7, 1, -22, 55, 35, -15, 20};

    for (int gap = sizeof(array) / 8; gap > 0; gap/=2) {
        for (int i = gap; i < sizeof(array) / 4; ++i) {
            int mainValue = array[i];
            int j=i;

            while (j>=gap && mainValue < array[j-gap]){
                array[j] = array[j-gap];
                j-=gap;
            }
            array[j] = mainValue;
        }
    }

    for (int i = 0; i < sizeof(array) / 4; ++i) {
        printf("%i\n", array[i]);
    }

    return 0;
}