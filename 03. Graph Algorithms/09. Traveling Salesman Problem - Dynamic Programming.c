#include<stdio.h>

#define INF 2147483647

int ary[10][10], completed[10], numberVillages, cost = 0;

void travelingSalesmanProblem(int city);
int least(int c);

int main() {

    int singleSourceNode=0;

    int i, j;

    printf("Enter the number of villages: ");
    scanf("%d", &numberVillages);

    printf("\nEnter the Cost Matrix\n");

    for (i = 0; i < numberVillages; i++) {

        printf("\nEnter Elements of Row: %d\n", i + 1);

        for (j = 0; j < numberVillages; j++){
            scanf("%d", &ary[i][j]);
        }

        completed[i] = 0;
    }

    printf("\n\nThe cost list is:");

    for (i = 0; i < numberVillages; i++) {

        printf("\n");

        for (j = 0; j < numberVillages; j++){
            printf("\t%d", ary[i][j]);
        }
    }

    printf("\n\nThe Path is:\n");
    travelingSalesmanProblem(singleSourceNode);

    printf("\n\nMinimum cost is %d\n ", cost);

    return 0;
}

void travelingSalesmanProblem(int city) {

    int i, numberCity;

    completed[city] = 1;

    printf("%d--->", city + 1);
    numberCity = least(city);

    if (numberCity == 999) {
        numberCity = 0;
        printf("%d", numberCity + 1);
        cost += ary[city][numberCity];
        return;
    }

    travelingSalesmanProblem(numberCity);
}

int least(int c) {

    int i, nc = INF;
    int min = INF, kmin;

    for (i = 0; i < numberVillages; i++) {

        if ((ary[c][i] != 0) && (completed[i] == 0)){

            if (ary[c][i] + ary[i][c] < min) {
                min = ary[i][0] + ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
        }
    }

    if (min != INF){
        cost += kmin;
    }

    return nc;
}