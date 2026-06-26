char* findTheString(int** lcp, int lcpSize, int* lcpColSize) {
    int n = lcpSize;
    char* word = (char*)malloc((n + 1) * sizeof(char));
    
    // Initialize with 0 to track unassigned characters
    for (int i = 0; i < n; i++) word[i] = 0;
    word[n] = '\0';

    char curr_char = 'a';
    for (int i = 0; i < n; i++) {
        if (word[i] == 0) {
            // If we need more than 26 characters, it's impossible
            if (curr_char > 'z') {
                free(word);
                return "";
            }
            
            // Greedily assign the same character to all indices j 
            // where lcp[i][j] > 0
            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = curr_char;
                }
            }
            curr_char++;
        }
    }

    // Validation: The LCP matrix must be internally consistent
    // We check from the back to use the recursive property: 
    // lcp[i][j] = (word[i] == word[j]) ? (1 + lcp[i+1][j+1]) : 0
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int expected = 0;
            if (word[i] == word[j]) {
                expected = 1;
                if (i + 1 < n && j + 1 < n) {
                    expected += lcp[i + 1][j + 1];
                }
            }
            
            // If the provided matrix doesn't match the string we built, return ""
            if (lcp[i][j] != expected) {
                free(word);
                return "";
            }
        }
    }

    return word;
}