int scoreOfParentheses(char* s) {
    int len = strlen(s);
    int *stack = (int *)malloc(len * sizeof(int));
    int top = 0;
    stack[0] = 0;
    int i = 0;
    while(s[i] != '\0') {
        if (s[i] == '(') {
            top++;
            stack[top] = 0;
        }
        if (s[i] == ')') {
            int score = (stack[top] == 0) ? 1 : 2 * stack[top];
            top--;
            stack[top] += score;
        }
        i++;
    }
    int ans = stack[0];
    free(stack);
    return ans;
}