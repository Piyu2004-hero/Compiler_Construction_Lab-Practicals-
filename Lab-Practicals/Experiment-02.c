// WAP to identify macro definitions in an assembly language program. Extend the above program to implement Simple and recursive macro expansion.


#include <stdio.h>
#include <string.h>

int main() {
    char *program[] = {
        "MACRO",
        "INCR",
        "LDA VALUE",
        "ADD ONE",
        "STA VALUE",
        "MEND",
        "INCR",
        "END"
    };

    int i;
    int n = sizeof(program) / sizeof(program[0]);

    printf("Macro Definitions Identified:\n");
    printf("-----------------------------\n");

    for (i = 0; i < n && strcmp(program[i], "END") != 0; i++) {
        if (strcmp(program[i], "MACRO") == 0) {
            printf("Macro Name: %s\n", program[i + 1]);

            i += 2;

            while (i < n && strcmp(program[i], "MEND") != 0) {
                printf("%s\n", program[i]);
                i++;
            }

            printf("Macro definition completed.\n\n");
        }
    }

    return 0;
}


//Output:
// Macro Definitions Identified:
// -----------------------------
// Macro Name: INCR
// LDA VALUE
// ADD ONE
// STA VALUE
// Macro definition completed.

// PS C:\Users\aspire 5\Desktop\Lab_Practicals> 