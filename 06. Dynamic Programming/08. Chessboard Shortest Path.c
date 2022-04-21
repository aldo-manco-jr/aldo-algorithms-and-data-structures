#include <stdio.h>

#define SIZE 5

/*
 * Created by Aldo Manco
 */

int shortestPath(int chessboard[][SIZE], int x, int y);

int main() {

    int chessboard[SIZE][SIZE + 2] = {0};

    //printf("%i", shortestPath(chessboard, SIZE, SIZE));
    shortestPath(chessboard, SIZE, SIZE);

    return 0;
}

int shortestPath(int chessboard[][SIZE], int x, int y) {

    static int memo[SIZE][SIZE + 2];

    for (int i = SIZE - 1; i >= 0; --i) {
        for (int j = 0; j < SIZE - 2; ++j) {
            if (y < 1 || y >= SIZE - 1) {
                memo[i][j] = 2147483627;
            } else if (x == SIZE) {
                memo[i][j] = chessboard[i][j];
            } else if ((y >= 0 && y < SIZE) && (x < SIZE)) {
                memo[i][j] = chessboard[i][j] + min(memo[i + 1][j - 1], memo[i + 1][j], memo[i + 1][j + 1]);
            }
        }
    }

    int min = 2147483647;
    for (int k = 1; k < SIZE - 1; ++k) {
        if (min > memo[0][k]) {
            min = memo[0][k];
        }
    }

    for (int l = 0; l < SIZE; ++l) {
        for (int i = 0; i < SIZE+2; ++i) {
            printf("%i, ", memo[l][i]);
        }
        puts("");
    }

    return min;
}

int min(int x, int y, int z) {
    if (x <= z && x <= y) {
        return x;
    } else if (y <= z && y < x) {
        return y;
    } else if (z < x && z < y) {
        return z;
    }
}