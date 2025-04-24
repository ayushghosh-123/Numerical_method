#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float findValueAt(float x) {
    return x*x*x - 4*x - 9;
}

float bisect(float x1, float x2) {
    return (x1 + x2) / 2.0;
}

int main() {
    int maxIteration, i = 1;
    float x1, x2, x;

    printf("Enter Maximum number of Iterations: ");
    scanf("%d", &maxIteration);  // Corrected: use &

    // Loop to get valid boundaries

    while (1) {
        printf("Enter the value of x1 and x2 (starting boundaries): ");
        scanf("%f %f", &x1, &x2);

        if (findValueAt(x1) * findValueAt(x2) > 0) {
            printf("Invalid interval. f(x1) and f(x2) must have opposite signs.\n");
        } else {
            printf("Root lies between %f and %f\n", x1, x2);
            break;
        }
    }

    // Run the loop exactly for maxIteration times


    while (i <= maxIteration) {
        x = bisect(x1, x2);

        printf("Iteration = %d, Midpoint = %f, f(x) = %f\n", i, x, findValueAt(x));

        if (findValueAt(x) * findValueAt(x1) < 0) {
            x2 = x;
        } else {
            x1 = x;
        }

        i++;
    }

    printf("Approximate Root after %d iterations = %f\n", maxIteration, x);

    return 0;
}