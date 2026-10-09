// Write a program in C,C++ to print fibonacci series.


#include <stdio.h>

int main() {
    int n, a = 0, b = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive number.\n");
        return 0;
    }

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }

    printf("\n");
    return 0;
}


// Output:
// Enter the number of terms: 7
// Fibonacci Series: 0 1 1 2 3 5 8