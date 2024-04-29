// A c program to read a set of data points from user and compute interpolation value at
// specified point using Newton interpolation.


#include <stdio.h>

// Function to compute factorial
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to compute binomial coefficient
double binomial_coefficient(int n, int k) {
    return (double)factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to compute divided differences
void divided_differences(double x[], double y[], double dd[][10], int n) {
    for (int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to perform Newton interpolation
double newton_interpolation(double x[], double dd[][10], int n, double point) {
    double result = dd[0][0];
    double term = 1.0;
    for (int i = 1; i < n; i++) {
        term *= (point - x[i - 1]);
        result += (dd[0][i] * term);
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    double dd[10][10]; // Divided difference table
    divided_differences(x, y, dd, n);

    double point;
    printf("Enter the point for interpolation: ");
    scanf("%lf", &point);

    // Compute interpolation value
    double interpolated_value = newton_interpolation(x, dd, n, point);
    printf("Interpolated value at %.2lf is %.6lf\n", point, interpolated_value);
    printf("\nKailash Pantha");

    return 0;
}
