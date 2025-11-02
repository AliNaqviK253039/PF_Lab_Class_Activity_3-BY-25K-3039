#include <stdio.h>

#define MAX 3

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of first matrix (max 3): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns of second matrix (max 3): ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("\nMatrix multiplication not possible!\n");
        printf("Number of columns of first matrix must equal number of rows of second matrix.\n");
        return 0;
    }

    printf("\nEnter elements of first matrix (%dx%d):\n", r1, c1);
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter elements of second matrix (%dx%d):\n", r2, c2);
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            C[i][j] = 0;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix A (%dx%d):\n", r1, c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix B (%dx%d):\n", r2, c2);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            printf("%4d", B[i][j]);
        printf("\n");
    }

    printf("\nResultant Matrix C = A X B (%dx%d):\n", r1, c2);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%4d", C[i][j]);
        printf("\n");
    }

    return 0;
}

