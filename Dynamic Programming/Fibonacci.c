#include <stdio.h>
#include <stdlib.h>

/*
 * Created by Aldo Manco
 */

int main() {

    int *memo = (int*) calloc(11, sizeof(int));
    *(memo) = -1;
    *(memo+1) = -1;
    *(memo+2) = -1;
    *(memo+3) = -1;
    *(memo+4) = -1;
    *(memo+5) = -1;
    *(memo+6) = -1;
    *(memo+7) = -1;
    *(memo+8) = -1;
    *(memo+9) = -1;
    *(memo+10) = -1;

    for(int i=1; i<11; ++i){
        fibonacci(memo, i);
        printf("%i\n", memo[i]);
    }

    return 0;
}

int fibonacci(int *memo, int index){
    int tmp=0;
    if (memo[index] != -1) return memo[index];
    if (index<=2) tmp=1;
    else tmp = fibonacci(memo, index-1) + fibonacci(memo, index-2);
    memo[index] = tmp;
    return memo[index];
}