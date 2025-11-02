#include <stdio.h>

#define SIZE 3

int main() {
    int arr[SIZE][SIZE][SIZE];
    int i, j, k;
    int identical, c, r;

    printf("Enter elements of the 3󫢫 matrix:\n");

    for (i = 0; i < SIZE; i++) {
        printf("\n--- Enter elements for Layer %d ---\n", i + 1);
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\n=== DISPLAYING ALL 2D LAYERS ===\n");
    for (i = 0; i < SIZE; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                printf("%4d", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    printf("\n=== LAYER SIMILARITY ANALYSIS ===\n");

    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            identical = 1;
            for ( r = 0; r < SIZE; r++) {
                for ( c = 0; c < SIZE; c++) {
                    if (arr[i][r][c] != arr[j][r][c]) {
                        identical = 0;
                        break;
                    }
                }
                if (!identical) break;
            }

            if (identical)
                printf("? Layer %d and Layer %d are IDENTICAL.\n", i + 1, j + 1);
            else
                printf("? Layer %d and Layer %d are DISTINCT.\n", i + 1, j + 1);
        }
    }

    printf("\n=== COMPARISON COMPLETE ===\n");
    return 0;
}

