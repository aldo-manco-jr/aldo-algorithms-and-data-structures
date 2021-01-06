#include <stdio.h>
#include <math.h>

double power(double x, unsigned y) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x;
    }
    return power(x, y - 1) * x;
}

int main() {

    double sum = 0;

    for (size_t j = 2; j < 16; ++j) {
        for (size_t i = 1; i < 64; ++i) {
            sum += (1.0 / power(i, j));
        }
        printf("\n%.0lf", (power(M_PI, j))/sum);
        sum=0;
    }

    sum=0;

    for (size_t i = 1; i < 65536; ++i) {
        sum += (1.0 / power(i, 2));
    }

    printf("\n%lf", sum);
    return 0;
}