// To write a C program that parses a C source code string and identifies keywords, identifiers, operators, and special symbols.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "int", "char", "float", "double", "if", "else",
    "while", "for", "return", "void", "break", "continue"
};

int isKeyword(char str[]) {
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char code[500], token[100];
    int i = 0, j, k;

    printf("Enter a C source code statement:\n");
    fgets(code, sizeof(code), stdin);

    while (code[i] != '\0') {
        if (isspace((unsigned char)code[i])) {
            i++;
        }
        else if (isalpha((unsigned char)code[i]) || code[i] == '_') {
            j = 0;

            while (isalnum((unsigned char)code[i]) || code[i] == '_')
                token[j++] = code[i++];

            token[j] = '\0';

            if (isKeyword(token))
                printf("%s : Keyword\n", token);
            else
                printf("%s : Identifier\n", token);
        }
        else if (strchr("+-*/%=<>!&|", code[i]) != NULL) {
            printf("%c : Operator\n", code[i]);
            i++;
        }
        else if (strchr("(){}[],;.", code[i]) != NULL) {
            printf("%c : Special Symbol\n", code[i]);
            i++;
        }
        else if (isdigit((unsigned char)code[i])) {
            j = 0;

            while (isdigit((unsigned char)code[i]) || code[i] == '.') 
                token[j++] = code[i++];

            token[j] = '\0';
            printf("%s : Constant\n", token);
        }
        else {
            i++;
        }
    }

    return 0;
}


// Output:
// 