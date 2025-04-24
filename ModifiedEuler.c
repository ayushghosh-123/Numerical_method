#include <stdio.h>

// Function dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, xn, x, y, h, y_predict;
    int n, i;

    printf("Enter the values of x0, y0, xn and h:\n");
    scanf("%f%f%f%f", &x0, &y0, &xn, &h);

    // Initial values
    x = x0;
    y = y0;

    // Number of steps
    n = (int)((xn - x0) / h);

    // Modified Euler Method loop
    for (i = 0; i < n; i++) {
        float k1 = f(x, y);
        y_predict = y + h * k1;
        float k2 = f(x + h, y_predict);
        y = y + (h / 2) * (k1 + k2);
        x = x + h;
    }

    printf("The solution of the differential equation is y(%.2f) = %.6f\n", x, y);

    return 0;
}