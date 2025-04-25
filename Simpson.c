#include <stdio.h>
#include <math.h>

double f(double x){
    return x*x;
}


double Simpson_one_third(double x, double y, int n){

    if(n % 2 != 0){
        printf("Error: Number of sub-interval must be even \n");
        return 0;
    }

    double h = (y-x)/n;
    double sum = (f(x)+f(y));
    
    for(int i=1; i<n; i++){
        if(i % 2 == 0){
            sum += 2*f(x+i*h);
        }
        else{
            sum += 4*f(x+i*h);
        }
    }

    return h/3 * sum;

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