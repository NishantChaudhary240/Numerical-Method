//A c program to solve Poisson's Equation.
#include <stdio.h>
#include <math.h>

#define N 5
#define M 4
#define GX(x, y) -4.0

void initializeBoundaryConditions(float a[N + 2][M + 2], float xl, float xh, float yl) {
    float h = (xh - xl) / (N + 1);
    float x = xl;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 || i == N || j == 1 || j == M) {
                printf("a[%d,%d] = ", i, j);
                scanf("%f", &a[i][j]);
            }
        }
        x += h;
    }
}

void gaussSeidel(float a[N + 2][M + 2], float h, float ar) {
    float mer;
    int itr = 0;
    
    do {
        mer = 0.0;

        for (int i = 2; i < N; i++) {
            for (int j = 2; j < M; j++) {
                float t = (a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1] - (h * h * GX(i, j))) / 4;
                float e = fabs(a[i][j] - t);
                
                if (e > mer)
                    mer = e;
                
                a[i][j] = t;
            }
        }
        
        itr++;
    } while (mer > ar);
    
    printf("Converged after %d iterations.\n", itr);
    
    // Print the result to terminal
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            printf("%.6f\t", a[i][j]);
        printf("\n");
    }
}

int main() {
    float xl, xh, yl, ar;
    float a[N + 2][M + 2];

    printf("Enter xl: ");
    scanf("%f", &xl);
    printf("Enter xh: ");
    scanf("%f", &xh);
    printf("Enter yl: ");
    scanf("%f", &yl);
    printf("Enter the allowed error: ");
    scanf("%f", &ar);

    initializeBoundaryConditions(a, xl, xh, yl);

    float h = (xh - xl) / (N + 1);
    gaussSeidel(a, h, ar);
    printf("\nNishant Chaudhary");
    return 0;
}
