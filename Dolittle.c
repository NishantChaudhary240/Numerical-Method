//A c program to factorize matrix using Dolittle method.
#include<stdio.h>

int main() {
    float A[20][20] = {0}, L[20][20] = {0}, U[20][20];
    int i, j, k, n;

    // Input matrix A
    printf("Enter the order of square matrix: ");
    scanf("%d", &n);
    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter A[%d][%d] element: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // LU decomposition using Doolittle's method
    for(j = 0; j < n; j++) {
        for(i = 0; i < n; i++) {
            if(i <= j) {
                U[i][j] = A[i][j];
                for(k = 0; k < i; k++)
                    U[i][j] -= L[i][k] * U[k][j];
                if(i == j)
                    L[i][j] = 1;
                else
                    L[i][j] = 0;
            } else {
                L[i][j] = A[i][j];
                for(k = 0; k < j; k++)
                    L[i][j] -= L[i][k] * U[k][j];
                L[i][j] /= U[j][j];
                U[i][j] = 0;
            }
        }
    }

    // Display matrices L and U
    printf("\nLower triangular matrix (L):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%.2f\t", L[i][j]);
        printf("\n");
    }
    printf("\nUpper triangular matrix (U):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%.2f\t", U[i][j]);
        printf("\n");
    }
    printf("\nKailash Pantha");
    return 0;
}
