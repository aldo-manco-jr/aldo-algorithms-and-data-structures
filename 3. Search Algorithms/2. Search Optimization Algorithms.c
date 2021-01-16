#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define QUANTUM_SIZE 0.1

/*
 * Created by Aldo Manco
 */

double f(double x);

double bruteForceSearch(double startPointX, double endPointX);

double generateRandomNumber(double min, double max);

double stochasticSearch(double startPointX, double endPointX);

double aldoStochasticSearch(double startPointX, double endPointX);

double hillClimbingSearch(double startPointX);

int main() {

    double startPointX = -2;
    double endPointX = 2;

    bruteForceSearch(startPointX, endPointX);
    stochasticSearch(startPointX, endPointX);
    //aldoStochasticSearch(startPointX, endPointX);
    hillClimbingSearch(startPointX);

    return 0;
}

double f(double x) {
    return pow(x, 2);
}

double bruteForceSearch(double startPointX, double endPointX) {

    double globalMaxima = f(startPointX);

    for (double i = startPointX; i < endPointX; i += QUANTUM_SIZE) {

        if (f(i) > globalMaxima) {
            globalMaxima = f(i);
        }
    }

    printf("Brute-Force Search: Global Maximum is: %.2lf", globalMaxima);
}

double generateRandomNumber(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

double stochasticSearch(double startPointX, double endPointX) {

    double globalMaximaApproximation = f(startPointX);

    for (int i = 0; i < 100000; i++) {

        double randomPoint = generateRandomNumber(startPointX, endPointX);

        if (f(randomPoint) > globalMaximaApproximation) {
            globalMaximaApproximation = f(randomPoint);
        }
    }

    printf("\nStochastic Search: Global Maximum Approximation is: %.2lf", globalMaximaApproximation);
}

double aldoStochasticSearch(double startPointX, double endPointX) {

    double globalMaximaApproximation = f(startPointX);

    for (int i = 0; i < 10; i++) {

        double randomPoint = generateRandomNumber(startPointX, endPointX);

        double localMaxima = hillClimbingSearch(randomPoint);

        if (localMaxima > globalMaximaApproximation) {
            globalMaximaApproximation = f(randomPoint);
        }
    }

    printf("\nAldo's Stochastic Search: Global Maximum Approximation is: %.2lf", globalMaximaApproximation);
}

double hillClimbingSearch(double startPointX) {

    double localMaxima = f(startPointX);

    while (f(startPointX + QUANTUM_SIZE) >= localMaxima) {
        localMaxima = f(startPointX + QUANTUM_SIZE);
        //printf("X: %.2lf\nY: %.2lf", startPointX, f(startPointX));
        startPointX += QUANTUM_SIZE;
    }

    printf("\nHill Climbing Search: First Local Maximum Found is: %.2lf", localMaxima);
}