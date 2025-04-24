// 16. Gauss elimination to solve a system of linear equations

/*  System of linear equation by gauss elimination method */

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float a[10][10], al[10][10], au[10][10], b[10], z[10], x[10], t, p;
    float sum;
    int m, n, i, j, k, l;
    m = 3;
    n = 4;
    printf("give the elements of matrix: \n");

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);
    }

    printf("the given matrix is: \n");

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%5.2f\t", a[i][j]);
        printf("\n");
    }

    for (k = 1; k <= m - 1; k++)
    {
        for (i = k + 1; i <= m; i++)
        {
            t = a[i][k] / a[k][k];
            for (j = k; j <= n; j++)
            {
                a[i][j] = a[i][j] - t * a[k][j];
            }
        }
    }
    printf("The upper triangularmatrix is:\n");


    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%5.2f\t", a[i][j]);
        printf("\n");
    }

    x[m] = a[m][n] / a[m][m];

    for (i = m - 1; i >= 1; i--)
    {
        sum = 0.0;
        for (j = i + 1; j <= n - 1; j++)
        {
            p = a[i][j] * x[j];
            sum = sum + p;
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }
    
    printf("the solution of the system of linear equation is\n");
    for (i = 1; i <= m; i++)
        printf("x[%d]=%f\n", i, x[i]);
    return 0;
}