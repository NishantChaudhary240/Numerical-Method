// A c program to calculate the root of x3-3x-2 using Newton-Raphson method.
#include <stdio.h>
#include <math.h>

/* Define the equation */
#define f(x) (x * x * x - 3 * x - 2)

/* Define the derivative of the equation */
#define df(x) (3 * x * x - 3)

/* Define the maximum number of iterations */
#define MAX_ITER 100

int main()
{
    double x0, x1, error, e;

    /* Input initial guess and error precision */
    printf("Enter initial guess: ");
    scanf("%lf", &x0);
    printf("Enter error precision: ");
    scanf("%lf", &e);

    int iter = 1;
    printf("\nIteration\t x\t\t f(x)\t\t f'(x)\t\t Error\n");
    do
    {
        /* Calculate function value and derivative */
        double fx0 = f(x0);
        double dfx0 = df(x0);

        /* Calculate next approximation */
        x1 = x0 - fx0 / dfx0;

        /* Calculate error */
        error = fabs(x1 - x0);

        /* Print iteration details */
        printf("%d\t\t %.6f\t %.6f\t %.6f\t %.6f\n", iter, x0, fx0, dfx0, error);

        /* Update the current approximation */
        x0 = x1;

        iter++;

        /* Check if maximum iterations reached */
        if (iter > MAX_ITER)
        {
            printf("Maximum number of iterations reached.\n");
            break;
        }
    } while (error > e);

    /* Print the root */
    printf("\nRoot is: %.6f\n", x1);
    printf("\nKailash Pantha");

    return 0;
}
