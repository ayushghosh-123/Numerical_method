#include <stdio.h>

int main() {
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double y[n];
    printf("Enter y values:\n");
    for(int i = 0; i < n; i++) {
        printf("y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    // Forward difference table
    double forward[n][n];
    for(int i = 0; i < n; i++) forward[0][i] = y[i];
    
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n-i; j++)
            forward[i][j] = forward[i-1][j+1] - forward[i-1][j];

    // Backward difference table
    double backward[n][n];
    for(int i = 0; i < n; i++) backward[0][i] = y[i];
    
    for(int i = 1; i < n; i++)
        for(int j = n-1; j >= i; j--)
            backward[i][j] = backward[i-1][j] - backward[i-1][j-1];

    // Print tables
    printf("\nForward Difference Table:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++)
            printf("%8.4lf ", forward[i][j]);
        printf("\n");
    }

    printf("\nBackward Difference Table:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++)
            printf("        "); // Alignment spaces
        for(int j = i; j < n; j++)
            printf("%8.4lf ", backward[i][j]);
        printf("\n");
    }

    return 0;
}