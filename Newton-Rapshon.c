#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

float f(float x) {
    return x * x * x - 3 * x - 5;  // Function: f(x) = x³ - 3x - 5
}

float differentiate(float x) {
    return 3 * x * x - 3;  // Derivative: f'(x) = 3x² - 3
}

int main() {

    int maxIteration, i;
    float x1, x2, x, x0;

    printf("Enter Maximum number of Iterations: ");
    scanf("%d", &maxIteration);

    // Input boundary values for root (used for checking if root exists in interval)

    do {
        printf("Enter the value of x1 and x2 (starting boundaries): ");
        scanf("%f %f", &x1, &x2);

        if (f(x1) * f(x2) < 0) {
            printf("Roots lie between %f and %f\n", x1, x2);
            break;  // valid root interval, exit loop
        } else {
            printf("Invalid interval! Try again.\n");
        }
    } while (1);


    // Choose the starting point x0
    if (fabs(f(x1)) < fabs(f(x2))) {
        x0 = x1;
    } else {
        x0 = x2;
    }

    // Newton-Raphson Iteration


    for (i = 1; i <= maxIteration; i++) {
        
        float f_x0 = f(x0);
        float f_prime_x0 = differentiate(x0);

        if (f_prime_x0 == 0) {
            printf("Derivative is zero. Newton-Raphson method fails.\n");
            return 1;
        }

        x = x0 - (f_x0 / f_prime_x0);

        printf("Iteration %d: x = %f\n", i, x);

        if (fabs(x - x0) < EPSILON) {
            printf("Converged to root after %d iterations. Root = %f\n", i, x);
            return 0;
        }

        x0 = x;
    }

    printf("Did not converge within %d iterations. Last approximation = %f\n", maxIteration, x);
    return 0;
}