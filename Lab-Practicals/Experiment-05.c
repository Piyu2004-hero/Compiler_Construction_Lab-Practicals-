// To demnonstrate source code optimizartion using operator strength reduction, dead code elimination and frequency reduction techniques.



#include <stdio.h>

int main() {
    int n, i, x, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Original code
    printf("\n--- Original Code ---\n");
    for (i = 1; i <= n; i++) {
        x = i * 2;          // Multiplication
        result = n * 10;    // Repeated calculation
        printf("%d ", x);
    }

    int dead = 100;         // Dead code: value never used

    // Optimized code
    printf("\n\n--- Optimized Code ---\n");
    result = n * 10;        // Frequency reduction: calculate once

    for (i = 1; i <= n; i++) {
        x = i + i;          // Strength reduction example
        printf("%d ", x);
    }

    printf("\nResult = %d\n", result);

    return 0;
}


// Output:
// Enter a number: 5

// --- Original Code ---
// 2 4 6 8 10 

// --- Optimized Code ---
// 2 4 6 8 10 
// Result = 50