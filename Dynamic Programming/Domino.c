#include <stdio.h>

/*
 * Created by Aldo Manco
 */

int dynamicDomino(int *, int);
int iterativeDomino(int *memo, int n);

int main() {

    int n = 20;
    int memo[n + 1];

    for (int i = 0; i < n; ++i) {
        memo[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        printf("%i, ", dynamicDomino(memo, i));
    }

    puts("");

    for (int i = 0; i < n; ++i) {
        printf("%i, ", iterativeDomino(memo, i));
    }

    return 0;
}

int dynamicDomino(int *memo, int n) {

    if (memo[n] != -1) {
        return memo[n];
    }

    if (n <= 1) {
        memo[n] = 1;
    } else {
        memo[n] = dynamicDomino(memo, n - 1) + dynamicDomino(memo, n - 2);
    }

    return memo[n];
}

int iterativeDomino(int *memo, int n){

    memo[0] = 1;
    memo[1] = 1;

    for (int i = 2; i <= n; ++i) {
        memo[n] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}