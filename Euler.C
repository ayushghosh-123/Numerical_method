#include <stdio.h>

// Define the function dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, xn, x, y, h;
    int n, i;

    // Input
    printf("Enter the values of x0, y0, xn and h:\n");
    scanf("%f%f%f%f", &x0, &y0, &xn, &h);

    // Initial values
    x = x0;
    y = y0;

    // Number of steps
    n = (int)((xn - x0) / h);

    // Euler's Method loop
    for (i = 0; i < n; i++) {
        y = y + h * f(x, y);
        x = x + h;
    }

    // Output
    printf("The solution of the differential equation is y(%.2f) = %.6f\n", x, y);

    return 0;
}