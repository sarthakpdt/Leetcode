char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    if (k >= len) return "0";
    char *stack = (char *)malloc((len + 1) * sizeof(char));
    int top = -1;
    for (int i = 0; num[i] != '\0'; i++) {
        while (top >= 0 && stack[top] > num[i] && k > 0) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }
    while (k > 0 && top >= 0) {
        top--;
        k--;
    }
    stack[top + 1] = '\0';
    int start = 0;
    while (start <= top && stack[start] == '0') {
        start++;
    }
    if (start > top) return "0";
    return &stack[start];
}