char* reversePrefix(char* word, char ch) {
    int i = 0;

    // Find the first occurrence of ch
    while (word[i] != '\0' && word[i] != ch) {
        i++;
    }

    // If ch is not found, return the word as is
    if (word[i] == '\0') {
        return word;
    }

    // Reverse from 0 to i
    int start = 0, end = i;
    while (start < end) {
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }

    return word;
}