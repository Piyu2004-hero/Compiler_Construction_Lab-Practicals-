//Parse tree of Arithmetic Statements in C.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char value[20];
    struct Node *left, *right;
};

struct Node *stack[100];
int top = -1;

struct Node *newNode(char value[]) {
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));

    strcpy(node->value, value);
    node->left = node->right = NULL;

    return node;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        if (root->left) printf("(");
        inorder(root->left);
        printf("%s", root->value);
        inorder(root->right);
        if (root->right) printf(")");
    }
}

void printTree(struct Node *root, int space) {
    if (root == NULL) return;

    space += 5;
    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%s\n", root->value);

    printTree(root->left, space);
}

int main() {
    char expr[200], token[20];
    int i = 0, j;

    printf("Enter postfix expression (e.g. a b c * +): ");
    fgets(expr, sizeof(expr), stdin);

    while (expr[i] != '\0') {
        if (isspace((unsigned char)expr[i])) {
            i++;
            continue;
        }

        j = 0;
        while (expr[i] != '\0' &&
               !isspace((unsigned char)expr[i])) {
            token[j++] = expr[i++];
        }
        token[j] = '\0';

        if (strlen(token) == 1 &&
            strchr("+-*/", token[0]) != NULL) {
            if (top < 1) {
                printf("Invalid postfix expression.\n");
                return 1;
            }

            struct Node *node = newNode(token);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        } else {
            stack[++top] = newNode(token);
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression.\n");
        return 1;
    }

    printf("\nInfix Expression: ");
    inorder(stack[top]);

    printf("\n\nParse Tree:\n");
    printTree(stack[top], 0);

    return 0;
}


// Output:
// Infix Expression: (a+(b*c))

// Parse Tree:

//           c

//      *
//           b

// +
//      a