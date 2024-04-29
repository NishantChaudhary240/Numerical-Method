//A c program to integrate a given function using Simpsons 1/3 rule.
#include <stdio.h>
#include<math.h>
double f(double x)
{
    return sqrt(sin(x));
}
double simpsons_one_third(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
    {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    for (int i = 2; i < n - 1; i += 2)
    {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    return (h / 3) * sum;
}
int main()
{
    double a, b;
    int n;
    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);
    printf("Enter the number of intervals (must be even): ");
    scanf("%d", &n);
    if (n <= 0 || n % 2 != 0)
    {
        printf("Number of intervals should be a positive even number.\n");
        return 1;
    }
    double integral = simpsons_one_third(a, b, n);
    printf("Approximate value of the integral: %.6lf\n", integral);
    printf("\nKailash Pantha");
    return 0;
}
