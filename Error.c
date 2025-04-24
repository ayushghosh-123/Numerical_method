#include <stdio.h>;
#include <math.h>;

int main(){

    double exact, approximate;
    printf("enter the exact and approximate values: \n");
    scanf("%lf", exact);
    scanf("%lf", approximate);

    double absolute_error = fabs(approximate - exact);
    double relative_error = absolute_error/fabs(exact);
    double percentage_error = relative_error * 100;

    printf("absolute error value of this: \n", absolute_error);
    printf("relative error value of this \n", relative_error);
    printf("percentage error value of this \n", percentage_error);

    return 0;
}