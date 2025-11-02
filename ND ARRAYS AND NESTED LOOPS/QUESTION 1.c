#include <stdio.h>

int main() {
    float a[3][3], trans[3][3], cofactor[3][3], adj[3][3], inv[3][3];
    int i, j;
    float det;

    printf("Enter elements of 3x3 matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            trans[i][j] = a[j][i];
        }
    }

    printf("\nTranspose of Matrix (A^T):\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%.2f\t", trans[i][j]);
        }
        printf("\n");
    }
    det = a[0][0]*(a[1][1]*a[2][2] - a[2][1]*a[1][2])
        - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
        + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);

    printf("\nDeterminant = %.2f\n", det);

    if(det == 0) {
        printf("\nMatrix has no inverse (determinant is 0).\n");
        return 0;
    }

    cofactor[0][0] =  (a[1][1]*a[2][2] - a[1][2]*a[2][1]);
    cofactor[0][1] = -(a[1][0]*a[2][2] - a[1][2]*a[2][0]);
    cofactor[0][2] =  (a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    cofactor[1][0] = -(a[0][1]*a[2][2] - a[0][2]*a[2][1]);
    cofactor[1][1] =  (a[0][0]*a[2][2] - a[0][2]*a[2][0]);
    cofactor[1][2] = -(a[0][0]*a[2][1] - a[0][1]*a[2][0]);
    cofactor[2][0] =  (a[0][1]*a[1][2] - a[0][2]*a[1][1]);
    cofactor[2][1] = -(a[0][0]*a[1][2] - a[0][2]*a[1][0]);
    cofactor[2][2] =  (a[0][0]*a[1][1] - a[0][1]*a[1][0]);

    printf("\nCofactor Matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%.2f\t", cofactor[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            adj[i][j] = cofactor[j][i];
        }
    }

    printf("\nAdjoint Matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%.2f\t", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nInverse of Matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            inv[i][j] = adj[i][j] / det;
            printf("%.4f\t", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}

