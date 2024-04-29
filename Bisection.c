/* Defining the equation to be solved. Change this equation to solve another problem. */
#include<stdio.h>
#include<math.h>
#define f(x) (4 * pow(x, 3) - 2 * x + 6)

int main() {
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1;

    /* Inputs */
    printf("Enter two initial guesses:\n");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);

    /* Calculating Functional Value */
    f0 = f(x0);
    f1 = f(x1);

    /* Checking whether given guesses bracket the root or not. */
    if (f0 * f1 > 0.0) {
        printf("Incorrect Initial Guesses.\n");
        return 1; // Exit with an error code
    }

    /* Implementing Bisection Method */
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        step++;
    } while (fabs(f2) > e);

    printf("\nRoot is: %f\n", x2);

    /* Print your name or any custom message */
    printf("\nKailash Pantha\n");

    return 0; // Exit successfully
}