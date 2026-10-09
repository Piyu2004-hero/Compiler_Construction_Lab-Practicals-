// To design a simple high-level language containing arithmetic and logical operations, pointer, branch, instructions and loop instructions.



#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char code[200];

    printf("Simple High-Level Language\n");
    printf("--------------------------\n");
    printf("Supported operations:\n");
    printf("Arithmetic, Logical, Pointer, Branch, Loop\n");

    printf("\nEnter an instruction: ");
    fgets(code, sizeof(code), stdin);

    if (strchr(code, '+') || strchr(code, '-') ||
        strchr(code, '*') || strchr(code, '/')) {
        printf("Type: Arithmetic Operation\n");
    }
    else if (strstr(code, "&&") || strstr(code, "||") ||
             strstr(code, "!")) {
        printf("Type: Logical Operation\n");
    }
    else if (strchr(code, '&') || strchr(code, '*')) {
        printf("Type: Pointer Operation\n");
    }
    else if (strstr(code, "if") || strstr(code, "else") ||
             strstr(code, "goto")) {
        printf("Type: Branch Instruction\n");
    }
    else if (strstr(code, "for") || strstr(code, "while") ||
             strstr(code, "do")) {
        printf("Type: Loop Instruction\n");
    }
    else {
        printf("Unknown or unsupported instruction.\n");
    }

    return 0;
}


// Output:
// Simple High-Level Language
// --------------------------
// Supported operations:
// Arithmetic, Logical, Pointer, Branch, Loop

// Enter an instruction: a + b
// Type: Arithmetic Operation