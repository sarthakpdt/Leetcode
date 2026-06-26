char* decodeString(char* s) {
    int len = strlen(s);
    int* countsStack = (int*)malloc(len * sizeof(int));
    char** stringsStack = (char**)malloc(len * sizeof(char*));
    int countsTop = -1, stringsTop = -1, k = 0, currentLen = 0;
    char* currentStr = (char*)malloc(100005 * sizeof(char));
    currentStr[0] = '\0';
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            k = k * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            countsStack[++countsTop] = k;
            stringsStack[++stringsTop] = strdup(currentStr);
            currentStr[0] = '\0';
            currentLen = 0;
            k = 0;
        } else if (s[i] == ']') {
            int repeatCount = countsStack[countsTop--];
            char* prevStr = stringsStack[stringsTop--];
            char* temp = (char*)malloc(100005 * sizeof(char));
            strcpy(temp, prevStr);
            free(prevStr);
            for (int r = 0; r < repeatCount; r++) {
                strcat(temp, currentStr);
            }
            strcpy(currentStr, temp);
            currentLen = strlen(currentStr);
            free(temp);
        } else {
            currentStr[currentLen++] = s[i];
            currentStr[currentLen] = '\0';
        }
    }
    free(countsStack);
    free(stringsStack);
    return currentStr;
}