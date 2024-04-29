//A c program to integrate a given function using trapezoidal rule.
#include <stdio.h>
#include <math.h>
double f(double x)
{
    return sqrt(1 + x * x);
}
double trapezoidal_rule(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += f(x);
    }
    return h * sum;
}
int main()
{
    double a, b;
    int n;
    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);
    printf("Enter the number of intervals: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Number of intervals should be positive.\n");
        return 1;
    }
    double integral = trapezoidal_rule(a, b, n);
    printf("Approximate value of the integral: %.6lf\n", integral);
    printf("\nKailash Pantha");
    return 0;
}
