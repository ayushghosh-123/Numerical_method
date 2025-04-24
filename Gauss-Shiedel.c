#include <stdio.h>
#include <math.h>


float f1(float y, float z)
{
    float u;
    u = (9 - 2 * y - z) / 10.0;
    return (u);
}


float f2(float x, float z)
{
    float v;
    v = (-22 - x + z) / 10.0;
    return (v);
}


float f3(float x, float y)
{
    float w;
    w = (22 + 2 * x - 3 * y) / 10.0;
    return (w);
}


int main()
{
    float x, y, z, x1, y1, z1, eps = 0.00001;
    printf("Enter the initial approximation of the solutions");
    scanf("%f%f%f", &x, &y, &z);
    do
    {
        x1 = x;
        y1 = y;
        z1 = z;
        x = f1(y, z);
        y = f2(x, z);
        z = f3(x, y);

        printf("The solution of the system is x=%f \t y=%f \t z=%f\n", x, y, z);
    } while (fabs(x1 - x) > eps || (y1 - y) > eps || (z1 - z) > eps);
    printf("The solution of the system is x=%f \t y=%f \t z=%f", x, y, z);
    return 0;
}