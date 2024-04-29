#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define function f(x) which is to be solved */
#define f(x) (x * x - x - 1)

/* Write f(x) as x = g(x) and define g(x) here */
#define g(x) (1 + 1 / x)

int main()
{
    int step = 1;
    float x0, x1, e;
    float error; // Declare the error variable here
    /* Inputs */
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);

    /* Implementing Fixed Point Iteration */
    printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\t\terror\n");
    do
    {
        x1 = g(x0);
        error = fabs(x1 - x0); // Calculate error

        printf("%d\t%f\t%f\t%f\t%f\t%f\n", step, x0, f(x0), x1, f(x1), error);

        x0 = x1;
        step++;

    } while (error > e); // Repeat until error is less than error precision

    printf("\nRoot is %f", x1);
    printf("\nKailash Pantha");
    return 0;
}
