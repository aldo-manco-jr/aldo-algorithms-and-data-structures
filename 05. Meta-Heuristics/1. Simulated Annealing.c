#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_COORDINATE -2
#define MAX_COORDINATE 2
#define MIN_TEMPERATURE 1
#define START_TEMPERATURE 100
#define COOLING_RATE 0.02

/*
 * Created by Aldo Manco
 */

double f(double x);

double generateRandomNumber(double min, double max);

void findGlobalSolutions();

double getEnergy(double x);

double acceptanceProbability(double energy, double newEnergy, double temperature);

int main() {

    findGlobalSolutions();

    return 0;
}

double f(double x) {
    return (x - 0.3) * (x - 0.3) * (x - 0.3) - 5 * x + x * x - 2;
}

double generateRandomNumber(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void findGlobalSolutions() {

    double currentCoordinateX;
    double nextCoordinateX;
    double globalMaximaCoordinateX;
    double globalMinimaCoordinateX;

    double temperature = START_TEMPERATURE;

    while (temperature > MIN_TEMPERATURE) {

        nextCoordinateX = generateRandomNumber(MIN_COORDINATE, MAX_COORDINATE);

        double currentStateEnergy = getEnergy(currentCoordinateX);
        double neighborStateEnergy = getEnergy(nextCoordinateX);


        if (acceptanceProbability(currentStateEnergy, neighborStateEnergy, temperature) > generateRandomNumber(0, 1)) {
            currentCoordinateX = nextCoordinateX;
        }

        if (f(currentCoordinateX) < f(globalMinimaCoordinateX)) {
            globalMinimaCoordinateX = currentCoordinateX;
        }

        if (f(currentCoordinateX) > f(globalMaximaCoordinateX)) {
            globalMaximaCoordinateX = currentCoordinateX;
        }

        temperature *= 1 - COOLING_RATE;
    }

    printf("\nGlobal Minima:\nx = %lf\nf(x) = %lf\n", globalMinimaCoordinateX, f(globalMinimaCoordinateX));
    printf("\nGlobal Maxima:\nx = %lf\nf(x) = %lf\n", globalMaximaCoordinateX, f(globalMaximaCoordinateX));
}

double getEnergy(double x) {
    return f(x);
}

double acceptanceProbability(double currentStateEnergy, double neighborStateEnergy, double temperature) {

    if (neighborStateEnergy < currentStateEnergy) {
        return 1.0;
    }

    return pow(M_E, ((currentStateEnergy - neighborStateEnergy) / temperature));
}