char* generateString(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    int totalLen = n + m - 1;

    char* res = (char*)malloc((totalLen + 1) * sizeof(char));
    bool* fixed = (bool*)calloc(totalLen, sizeof(bool));
    
    for (int i = 0; i < totalLen; i++) res[i] = 'a';
    res[totalLen] = '\0';

    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = 0; j < m; j++) {
                if (fixed[i + j] && res[i + j] != str2[j]) {
                    free(res);
                    free(fixed);
                    return "";
                }
                res[i + j] = str2[j];
                fixed[i + j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (str1[i] == 'F') {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (res[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                bool possible = false;
                for (int j = m - 1; j >= 0; j--) {
                    if (!fixed[i + j]) {
                        res[i + j] = 'b';
                        possible = true;
                        break;
                    }
                }
                if (!possible) {
                    free(res);
                    free(fixed);
                    return "";
                }
            }
        }
    }

    free(fixed);
    return res;
}