#include <stdio.h>

int main() {
    int marks, i = 0, passCount = 0, failCount = 0;
    float pass[10], fail[10];
    float passSum = 0, failSum = 0;

    printf("Enter quiz marks for up to 10 students (-1 to stop):\n");

    while (i < 10) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks);

        if (marks == -1)
            break;

        if (marks >= 5 && marks <= 10) {
            pass[passCount] = marks;
            passSum += marks;
            passCount++;
        }
        else if (marks >= 0 && marks < 5) {
            fail[failCount] = marks;
            failSum += marks;
            failCount++;
        }
        else {
            printf("? Invalid marks! Enter between 0 and 10.\n");
            continue;
        }

        i++;
    }

    printf("\nPassing Students (5–10):\n");
    if (passCount == 0)
        printf("None\n");
    else {
        for (i = 0; i < passCount; i++) {
            printf("%.2f ", pass[i]);
        }
        printf("\nAverage = %.2f\n", passSum / passCount);
    }

    printf("\nFailing Students (0–5):\n");
    if (failCount == 0)
        printf("None\n");
    else {
        for (i = 0; i < failCount; i++) {
            printf("%.2f ", fail[i]);
        }
        printf("\nAverage = %.2f\n", failSum / failCount);
    }

    return 0;
}
