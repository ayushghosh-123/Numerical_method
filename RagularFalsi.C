#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.0001

// Function for the equation f(x) = x^3 - 2x - 5
float findValueAt(float x) {
    return x * x * x - 2 * x - 5;
}

// Function to calculate new approximation using False Position Formula
float findX(float x1, float x2) {
    return (x1 * findValueAt(x2) - x2 * findValueAt(x1)) / (findValueAt(x2) - findValueAt(x1));
}

int main() {
    int maxIteration, i = 1;
    float x1, x2, x3, x;

    printf("Enter Maximum number of Iterations: ");
    scanf("%d", &maxIteration);

    // Input initial guess values
    do {
        printf("Enter the values of x1 and x2 (starting boundaries / initial roots): ");
        scanf("%f%f", &x1, &x2);

        if (findValueAt(x1) * findValueAt(x2) > 0) {
            printf("Invalid roots. f(x1) and f(x2) must have opposite signs.\n");
        } else {
            printf("Valid interval: Root lies between %f and %f\n", x1, x2);
            break;
        }
    } while (1);

    x = findX(x1, x2);

    do {
        if (findValueAt(x) * findValueAt(x1) < 0) {
            x2 = x;
        } else {
            x1 = x;
        }

        printf("Iteration %d: Root = %f\n", i, x);
        x3 = findX(x1, x2);

        if (fabs(x3 - x) < EPSILON) {
            printf("Final Root = %f found in %d iterations\n", x, i);
            return 0;
        }

        x = x3;
        i++;
    } while (i <= maxIteration);

    printf("Approximate Root = %f found in %d iterations\n", x, --i);

    return 0;
}