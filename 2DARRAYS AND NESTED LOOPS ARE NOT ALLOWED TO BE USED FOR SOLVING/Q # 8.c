#include <stdio.h>

int main() {
    char str[100]; 
    printf("Enter a string (it will only accept non-alphabetic characters):\n");

    scanf("%[^A-Z a-z]", str);

    printf("\nNon-alphabetic characters entered:\n");
    printf("%s\n", str);

    return 0;
}

