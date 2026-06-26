#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int calculate(char* s) {
    int len = strlen(s);
    // In the worst case, we might need to store signs and sums for nested parentheses
    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;

    int sum = 0;
    int sign = 1;

    for (int i = 0; i < len; i++) {
        if (isdigit(s[i])) {
            long long num = 0;
            // Form the full number if it has multiple digits
            while (i < len && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--; // Move index back since the loop increments it
            sum += num * sign;
        } 
        else if (s[i] == '+') {
            sign = 1;
        } 
        else if (s[i] == '-') {
            sign = -1;
        } 
        else if (s[i] == '(') {
            // Store current running sum and sign before entering parentheses
            stack[++top] = sum;
            stack[++top] = sign;
            // Reset for the inner expression
            sum = 0;
            sign = 1;
        } 
        else if (s[i] == ')') {
            // Inner expression is done. Pop the sign outside '('
            int external_sign = stack[top--];
            // Pop the accumulated sum before '('
            int previous_sum = stack[top--];
            
            // Apply the sign to the inner sum, then add to previous sum
            sum = previous_sum + (external_sign * sum);
        }
    }

    free(stack);
    return sum;
}