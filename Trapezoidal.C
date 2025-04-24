#include <stdio.h>
#include<math.h>

double f(double x){
    return x*x;
}

double Trapezoidal(double x, double y, int n){
    double h = (y-x)/n;
    double sum = (f(x)+f(y))/2.0;
    
    for(int i=1; i<n; i++){
        sum += f(x+i*h);
    }

    return h * sum;

}

int main(){
    double a, b;
    int n;

    printf("Enter the lower limit(a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit(b): ");
    scanf("%lf", &b);
    printf("Enter the number of sub-interval(n): ");
    scanf("%d", &n);

    double result = Trapezoidal(a, b, n);
    printf("The approximate integral value is:%lf\n", result);

    return 0; 

}

