int numberOfSpecialChars(char* word) {
    int count = 0;
    bool countt[26] = {false};
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (islower(word[i]) && !countt[word[i] - 'a']) {
            char tar = toupper(word[i]);
            int firstUpperIdx = -1;
            
            for (int j = 0; word[j] != '\0'; j++) {
                if (word[j] == tar) {
                    firstUpperIdx = j;
                    break;
                }
            }
            
            if (firstUpperIdx != -1) {
                bool isValid = true;
                for (int k = firstUpperIdx; word[k] != '\0'; k++) {
                    if (word[k] == word[i]) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    count++;
                }
            }
            countt[word[i] - 'a'] = true;
        }
    }
    return count;
}