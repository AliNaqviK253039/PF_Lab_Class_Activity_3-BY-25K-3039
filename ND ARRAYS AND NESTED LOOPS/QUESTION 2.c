#include <stdio.h>

#define MAX 5

int main() {
    int n, m, i, j, k;
    int A[MAX][MAX];
    int isSquare, isZero = 1, isIdentity = 1, isDiagonal = 1, isScalar = 1;
    int isUpper = 1, isLower = 1, isSymmetric = 1, isSkewSymmetric = 1;
    int isRow = 0, isColumn = 0, isIdempotent = 1, isNilpotent = 1;
    int determinant = 0;

    printf("Enter rows and columns (max 5): ");
    scanf("%d %d", &n, &m);

    printf("Enter elements of the matrix (%dx%d):\n", n, m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    isSquare = (n == m);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (A[i][j] != 0)
                isZero = 0;

    if (n == 1 && m > 1) isRow = 1;
    if (m == 1 && n > 1) isColumn = 1;

    if (isSquare) {
        int diagVal = A[0][0];

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
            	
                if (i == j) {
                    if (A[i][j] != 1) isIdentity = 0;
                } else {
                    if (A[i][j] != 0) isIdentity = 0;
                }

                if (i != j && A[i][j] != 0)
                    isDiagonal = 0;

                if (i != j && A[i][j] != 0)
                    isScalar = 0;

                if (i > j && A[i][j] != 0)
                    isUpper = 0;
                if (i < j && A[i][j] != 0)
                    isLower = 0;

                if (A[i][j] != A[j][i])
                    isSymmetric = 0;
                if (A[i][j] != -A[j][i])
                    isSkewSymmetric = 0;
            }
        }

        for (i = 0; i < n; i++)
            if (A[i][i] != diagVal)
                isScalar = 0;

        int B[MAX][MAX] = {0};
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    B[i][j] += A[i][k] * A[k][j];

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (B[i][j] != A[i][j])
                    isIdempotent = 0;

        int allZero = 1;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (B[i][j] != 0)
                    allZero = 0;
        if (allZero == 0) isNilpotent = 0;

        if (n == 2) {
            determinant = A[0][0]*A[1][1] - A[0][1]*A[1][0];
        } else if (n == 3) {
            determinant = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1])
                        - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0])
                        + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
        }
    }

    printf("\n=== MATRIX TYPES DETECTED ===\n");

    if (isSquare) printf("? Square Matrix\n");
    else printf("? Rectangular Matrix\n");

    if (isZero) printf("? Zero Matrix (also Null Matrix)\n");
    if (isIdentity) printf("? Identity Matrix\n");
    if (isDiagonal && !isIdentity && !isScalar) printf("? Diagonal Matrix\n");
    if (isScalar) printf("? Scalar Matrix\n");
    if (isUpper) printf("? Upper Triangular Matrix\n");
    if (isLower) printf("? Lower Triangular Matrix\n");
    if (isSymmetric) printf("? Symmetric Matrix\n");
    if (isSkewSymmetric) printf("? Skew-Symmetric Matrix\n");
    if (isRow) printf("? Row Matrix\n");
    if (isColumn) printf("? Column Matrix\n");
    if (isIdempotent) printf("? Idempotent Matrix\n");
    if (isNilpotent) printf("? Nilpotent Matrix\n");

    if (isSquare && (n == 2 || n == 3)) {
        printf("Determinant = %d ? ", determinant);
        if (determinant == 0)
            printf("? Singular Matrix\n");
        else
            printf("? Non-Singular Matrix\n");
    }

    char choice;
    printf("\nCompare with another matrix? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int B[MAX][MAX];
        int equal = 1;
        printf("Enter 2nd matrix (%dx%d):\n", n, m);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &B[i][j]);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (A[i][j] != B[i][j])
                    equal = 0;
        if (equal)
            printf("? Matrices are Equal\n");
        else
            printf("? Matrices are NOT Equal\n");
    }

    printf("==============================\n");
    return 0;
}

