#include <stdio.h>

/*
 * Created by Aldo Manco
 */

double knapsack(int weightKnapsack, int weightItems[], double valueItems[], int numberOfItems);

double max(double x, double y);

double recursiveKnapsack(int w, int weightItems[], double valueItems[], int i);

int main() {

    double memoValue[5] = {12.7, 6.4, 1.7, 0.3};

    int memoWeight[5] = {2, 7, 6, 4};

    int weightKnapsack = 10;

    printf("\n%.2f\n", recursiveKnapsack(weightKnapsack, memoWeight, memoValue, 4));

    return 0;
}

double knapsack(int weightKnapsack, int weightItems[], double valueItems[], int numberOfItems) {

    int i, w;
    double memo[numberOfItems + 1][weightKnapsack + 1];

    for (i = 0; i <= numberOfItems; i++) {
        for (w = 0; w <= weightKnapsack; w++) {
            if (i == 0 || w == 0) {
                memo[i][w] = 0.0;
            } else if (weightItems[i - 1] <= w) {
                memo[i][w] = max(valueItems[i - 1] + memo[i - 1][w - weightItems[i - 1]] * 1.0, memo[i - 1][w] * 1.0);
            } else if (weightItems[i - 1] > w) {
                memo[i][w] = memo[i - 1][w] * 1.0;
            }
            (memo[i][w] < 10) ? printf("0%.2f ", memo[i][w]) : printf("%.2f ", memo[i][w]);
        }
        puts("");
    }
    return memo[numberOfItems][weightKnapsack] * 1.0;
}

double recursiveKnapsack(int w, int weightItems[], double valueItems[], int i) {

    double memo[i + 1][w + 1];

    if (i == 0 || w == 0) {
        memo[i][w] = 0.0;
    } else if (weightItems[i - 1] <= w) {
        memo[i][w] = max(valueItems[i - 1] + recursiveKnapsack(w-weightItems[i-1], weightItems, valueItems, i-1) * 1.0, recursiveKnapsack(w, weightItems, valueItems, i-1) * 1.0);
    } else if (weightItems[i - 1] > w) {
        memo[i][w] = recursiveKnapsack(w, weightItems, valueItems, i-1);
    }
    return memo[i][w] * 1.0;
}

double max(double x, double y) {
    return (x > y) ? x * 1.0 : y * 1.0;
}