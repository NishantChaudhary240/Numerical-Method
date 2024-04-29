// A c program to solve system of non linear equations using Jacobi Iteration.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], ratio;
    int i, j, k, n;

    printf("Enter number of unknowns: ");
    scanf("%d", &n);

    if (n <= 0 || n > SIZE)
    {
        printf("Invalid number of unknowns. Please enter a value between 1 and %d.\n", SIZE);
        return 1;
    }

    /* Reading Augmented Matrix */
    printf("Enter coefficients of Augmented Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Applying Gauss Jordan Elimination */
    for (i = 1; i <= n; i++)
    {
        if (a[i][i] == 0.0)
        {
            printf("Mathematical Error!");
            exit(0);
        }
        for (j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ratio = a[j][i] / a[i][i];
                for (k = 1; k <= n + 1; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }
    }

    /* Obtaining Solution */
    for (i = 1; i <= n; i++)
    {
        x[i] = a[i][n + 1] / a[i][i];
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d] = %0.3f\n", i, x[i]);
    }
    printf("\nKailash Pantha");
    return 0;
}
