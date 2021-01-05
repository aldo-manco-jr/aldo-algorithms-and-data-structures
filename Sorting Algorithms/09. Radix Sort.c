#include <stdio.h>
#include <math.h>

/*
 * Created by Aldo Manco
 */

int main() {
    int radixArray[] = {4725, 4586, 1330, 8792, 1594, 5729};

    radixSort(radixArray, 6, 4, 10);

    for (int i = 0; i < 6; ++i) {
        printf("%i\n", radixArray[i]);
    }
    return 0;
}

void radixSort(int *radixArray, int length, int width, int radix){
    for (int i = 0; i < width; ++i) {
        singlyRadixSort(radixArray, 6, i, radix);
    }
}

void singlyRadixSort(int *radixArray, int length, int position, int radix){

    int countingArray[radix];

    for (int i = 0; i < length; ++i) {
        countingArray[getDigit(radixArray[i], position, radix)]++;
    }

    for (int i = 1; i < radix; ++i) {
        countingArray[i]+=countingArray[i-1];
    }

    int tmp[length];

    for (int i = length-1; i >= 0; --i) {
        tmp[--countingArray[getDigit(radixArray[i], position, radix)]] = radixArray[i];
    }

    for (int i = 0; i < length; ++i) {
        radixArray[i] = tmp[i];
    }
}

int getDigit(int value, int position, int radix){
    return value / (int) pow(10, position) % radix;
}