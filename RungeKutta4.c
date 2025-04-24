#include <stdio.h>
#include <math.h>

// Function dy/dx = f(x, y)
float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, xn, x, y, h, k1, k2, k3, k4, k;
    int n, i;

    printf("Enter the values of x0, y0, xn and h:\n");
    scanf("%f%f%f%f", &x0, &y0, &xn, &h);

    // Initial values
    x = x0;
    y = y0;

    // Number of steps

    
    n = (int)((xn - x0) / h);

    // Runge-Kutta loop


    for (i = 0; i < n; i++) {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        k4 = h * f(x + h, y + k3);
        
        k = (k1 + 2.0*(k2 + k3)+ k4)/6.0;
        y = y + k;
        x = x + h;
    }


    printf("The solution of the differential equation is y(%.2f) = %.6f\n", x, y);

    return 0;
}