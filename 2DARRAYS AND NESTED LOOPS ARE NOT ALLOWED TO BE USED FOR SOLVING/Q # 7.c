#include <stdio.h>

int main() {
    int arr[10];
    int i, j;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (arr[i] == arr[j] && arr[j] != -1) {
                arr[j] = -1; 
            }
        }
    }

    printf("\nUpdated array (duplicates replaced with -1):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}

