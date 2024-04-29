// A c program to calculate the root of x2-5x+6 using secant method.

#include <stdio.h>

#include <math.h>

#include <stdlib.h>

/* Defining equation to be solved */

#define f(x) (x * x - 5 * x + 6)

int main()
{

    float x0, x1, x2, f0, f1, f2, e;

    int step = 1;

    /* Inputs */

    printf("Enter initial guesses:\n");

    scanf("%f%f", &x0, &x1);

    printf("Enter tolerable error:\n");

    scanf("%f", &e);

    /* Check if initial guesses are too close */

    if (fabs(x1 - x0) < 1e-6)
    {

        printf("Initial guesses are too close. Please provide different guesses.\n");

        return 1; // Exit with an error code
    }

    /* Secant Method */

    printf("\nIteration\tx0\t\tx1\t\tx2\t\tf(x2)\t\terror\n");

    do
    {

        f0 = f(x0);

        f1 = f(x1);

        /* Check if division by zero will occur */

        if (f0 == f1)
        {

            printf("Mathematical Error.");

            return 1; // Exit with an error code
        }

        /* Calculate next approximation */

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);

        f2 = f(x2);

        /* Calculate error */

        float error = fabs(x2 - x1);

        /* Print iteration details */

        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", step, x0, x1, x2, f2, error);

        /* Update values for next iteration */

        x0 = x1;

        f0 = f1;

        x1 = x2;

        f1 = f2;

        step++;

    } while (fabs(f2) > e);

    /* Print the root */

    printf("\nRoot is: %.6f\n", x2);

    printf("\nKailash Pantha\n");

    return 0;
}