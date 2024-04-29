// A c program to read a set of data points from user and compute interpolation value at
// specified point using Lagrange interpolation.
#include <stdio.h>
// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
    int result = poly[0]; // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i = 1; i < n; i++)
        result = result * x + poly[i];

    return result;
}

// Driver program to test above function.
int main()
{
    // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
    int poly[] = {1, -4, 1, 6};
    int x = 2;
    int n = sizeof(poly) / sizeof(poly[0]);
    printf("Value of polynomial at x=%d is %d.", x, horner(poly, n, x));
    printf("\nKailash Pantha");
    return 0;
}
