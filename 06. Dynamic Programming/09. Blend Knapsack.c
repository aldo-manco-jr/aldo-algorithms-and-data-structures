#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define CARDINALITY 8
#define WEIGHT_KNAPSACK 20
#define NUMBER_OF_ITEMS_01_KNAPSACK 4

struct ItemFractionable {
    double profit;
    double weight;
    double density;
    struct ItemFractionable *next;
};

typedef struct ItemFractionable ItemFractionable;

struct Shop {
    int cardinality;
    ItemFractionable *listItemsFractionable;
};

typedef struct Shop Shop;


ItemFractionable *createItemFractionable(double, double);

Shop *createShop();

void addItemFractionable(Shop *, double, double);

double knapsackFractionableItems(Shop *shop, double capacityKnapsack);

void printShop(Shop *);

double knapsackNonDivisibleItems(int weightKnapsack, int weightItems[], double valueItems[], int numberOfItems);

double max(double x, double y);

double memo[NUMBER_OF_ITEMS_01_KNAPSACK + 1][WEIGHT_KNAPSACK + 1];

int main() {

    Shop *shop = createShop();
    addItemFractionable(shop, 10.0, 1.0);
    addItemFractionable(shop, 22.0, 4.0);
    addItemFractionable(shop, 34.0, 3.0);
    addItemFractionable(shop, 65.9, 4.0);
    addItemFractionable(shop, 2.0, 5.9);
    addItemFractionable(shop, 9.6, 6.8);
    addItemFractionable(shop, 17.6, 4.9);

    printShop(shop);

    printf("Greedy Knapsack, Optimal Solution: %.2lf\n\n", knapsackFractionableItems(shop, WEIGHT_KNAPSACK));

    double memoValue[NUMBER_OF_ITEMS_01_KNAPSACK+1] = {12.7, 6.4, 1.7, 0.3};
    int memoWeight[NUMBER_OF_ITEMS_01_KNAPSACK+1] = {2, 7, 6, 4};

    printf("\nKnapsack 0/1, Optimal Solution: %.2lf\n\n", knapsackNonDivisibleItems(WEIGHT_KNAPSACK, memoWeight, memoValue, NUMBER_OF_ITEMS_01_KNAPSACK));

    int arrayChosenItems[NUMBER_OF_ITEMS_01_KNAPSACK] = {0};
    for (int i = 1; i <= NUMBER_OF_ITEMS_01_KNAPSACK; i++) {
        if (memo[i][WEIGHT_KNAPSACK]!=memo[i-1][WEIGHT_KNAPSACK]){
            arrayChosenItems[i]=1;
        }
    }

    for (int i = 1; i <= NUMBER_OF_ITEMS_01_KNAPSACK; ++i) {
        if (arrayChosenItems[i]==1){
            printf("\n%d\n", i);
        }
    }

    double profit01Knapsack=0;
    double profitGreedyKnapsack=0;
    double arrayProfitBlendKnapsack[WEIGHT_KNAPSACK+1]={0};

    for (int i = 1; i < WEIGHT_KNAPSACK; ++i) {
        if (memo[NUMBER_OF_ITEMS_01_KNAPSACK][i]!=memo[NUMBER_OF_ITEMS_01_KNAPSACK][i-1]){
            profit01Knapsack = memo[NUMBER_OF_ITEMS_01_KNAPSACK][i];
            profitGreedyKnapsack = knapsackFractionableItems(shop, WEIGHT_KNAPSACK-i*1.0);
            arrayProfitBlendKnapsack[i] = profit01Knapsack+profitGreedyKnapsack;
        }
    }

    double bestProfitBlendKnapsack = 0;

    for (int i = 0; i < WEIGHT_KNAPSACK; ++i) {
        if (bestProfitBlendKnapsack<arrayProfitBlendKnapsack[i]){
            bestProfitBlendKnapsack=arrayProfitBlendKnapsack[i];
        }
    }

    printf("\nBlend Knapsack, Optimal Solution: %.2lf\n\n", bestProfitBlendKnapsack);

    return 0;
}

ItemFractionable *createItemFractionable(double profit, double weight) {

    ItemFractionable *newItemFractionable = malloc(sizeof(ItemFractionable));
    newItemFractionable->profit = profit;
    newItemFractionable->weight = weight;
    newItemFractionable->density = profit / weight;
    newItemFractionable->next = NULL;

    return newItemFractionable;
}

Shop *createShop() {

    Shop *shop = malloc(sizeof(Shop));
    shop->cardinality = 0;
    shop->listItemsFractionable = NULL;

    return shop;
}

void addItemFractionable(Shop *shop, double profitNewItemFractionable, double weightNewItemFractionable) {

    ItemFractionable *newItemFractionable = createItemFractionable(profitNewItemFractionable,
                                                                   weightNewItemFractionable);

    if (shop->listItemsFractionable == NULL || shop->listItemsFractionable->density < newItemFractionable->density) {

        newItemFractionable->next = shop->listItemsFractionable;
        shop->listItemsFractionable = newItemFractionable;

    } else {

        ItemFractionable *currentItemFractionable = shop->listItemsFractionable;

        while (currentItemFractionable->next != NULL &&
               currentItemFractionable->next->density > newItemFractionable->density) {
            currentItemFractionable = currentItemFractionable->next;
        }

        newItemFractionable->next = currentItemFractionable->next;
        currentItemFractionable->next = newItemFractionable;

        shop->cardinality++;
    }
}

double knapsackFractionableItems(Shop *shop, double capacityKnapsack){

    ItemFractionable *optimalItemFractionable = shop->listItemsFractionable;
    double profitEarned=0;
    double capacityRemaining=capacityKnapsack;

    while(optimalItemFractionable!=NULL){

        if (optimalItemFractionable->weight<=capacityRemaining){
            profitEarned+=optimalItemFractionable->profit;
            capacityRemaining-=optimalItemFractionable->weight;

        } else{
            double portion = capacityRemaining/optimalItemFractionable->weight;
            profitEarned+=optimalItemFractionable->profit*portion;
            capacityRemaining-=optimalItemFractionable->weight*portion;
        }

        optimalItemFractionable=optimalItemFractionable->next;
    }

    return profitEarned;
}

void printShop(Shop *shop) {

    ItemFractionable *currentItemFractionable = shop->listItemsFractionable;
    int i = 1;

    while (currentItemFractionable) {
        printf("Item Fractionable %d:\n", i);
        printf("%.2lf : %.2lf : %.2lf\n\n", currentItemFractionable->profit, currentItemFractionable->weight,
               currentItemFractionable->density);
        currentItemFractionable = currentItemFractionable->next;
        i++;
    }

    printf("\n");
}

double knapsackNonDivisibleItems(int weightKnapsack, int weightItems[], double valueItems[], int numberOfItems) {

    int i, w;

    for (i = 0; i <= numberOfItems; i++) {

        for (w = 0; w <= weightKnapsack; w++) {

            if (i == 0 || w == 0) {
                memo[i][w] = 0.0;
            }
            else if (weightItems[i - 1] <= w) {
                memo[i][w] = max(valueItems[i - 1] + memo[i - 1][w - weightItems[i - 1]] * 1.0, memo[i - 1][w] * 1.0);
            }
            else if (weightItems[i - 1] > w) {
                memo[i][w] = memo[i - 1][w] * 1.0;
            }

            (memo[i][w] < 10) ? printf("0%.2lf ", memo[i][w]) : printf("%.2lf ", memo[i][w]);
        }
        puts("");
    }

    return memo[numberOfItems][weightKnapsack] * 1.0;
}

double max(double x, double y) {
    return (x > y) ? x * 1.0 : y * 1.0;
}