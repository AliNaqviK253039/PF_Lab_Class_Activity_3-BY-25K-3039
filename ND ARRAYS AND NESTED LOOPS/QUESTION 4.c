#include <stdio.h>

#define SIZE 3

int main() {
    int arr[SIZE][SIZE][SIZE];
    int i, j, k;
    int totalSum = 0;
    int layerSum, layerMax, layerMin;
    int overallMax, overallMin;
    float overallAvg;

    printf("Enter elements of 3x3x3 array:\n");

    for (i = 0; i < SIZE; i++) {
        printf("\n--- Enter elements for Layer %d ---\n", i + 1);
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\n=== 3D ARRAY DATA ANALYSIS ===\n");

    overallMax = overallMin = arr[0][0][0];

    for (i = 0; i < SIZE; i++) {
        layerSum = 0;
        layerMax = arr[i][0][0];
        layerMin = arr[i][0][0];

        printf("\nLayer %d (2D slice):\n", i + 1);
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                printf("%4d", arr[i][j][k]);
                layerSum += arr[i][j][k];

                if (arr[i][j][k] > layerMax) layerMax = arr[i][j][k];
                if (arr[i][j][k] < layerMin) layerMin = arr[i][j][k];

                if (arr[i][j][k] > overallMax) overallMax = arr[i][j][k];
                if (arr[i][j][k] < overallMin) overallMin = arr[i][j][k];
            }
            printf("\n");
        }

        printf("  Layer %d Total = %d\n", i + 1, layerSum);
        printf("  Layer %d \n Max = %d, Min = %d\n", i + 1, layerMax, layerMin);

        totalSum += layerSum;
    }

    overallAvg = (float)totalSum / (SIZE * SIZE * SIZE);

    printf("\n=== OVERALL DATA INSIGHTS ===\n");
    printf("Total Sum of All Elements = %d\n", totalSum);
    printf("Overall Average Value = %.2f\n", overallAvg);
    printf("Overall Maximum Value = %d\n", overallMax);
    printf("Overall Minimum Value = %d\n", overallMin);

    printf("==============================\n");

    return 0;
}

