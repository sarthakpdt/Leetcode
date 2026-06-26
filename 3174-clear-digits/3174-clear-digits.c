#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isdigit()

char* clearDigits(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc(len + 1);
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            // Remove the closest non-digit character to the left if any
            if (top >= 0) {
                top--; // pop the non-digit character
            }
            // Do not push the digit
        } else {
            // Push non-digit character
            stack[++top] = s[i];
        }
    }
    stack[top + 1] = '\0'; // Null-terminate the result
    return stack;
}
