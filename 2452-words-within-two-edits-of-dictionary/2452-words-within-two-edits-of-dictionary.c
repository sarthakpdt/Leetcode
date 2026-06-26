char** twoEditWords(char** queries, int queriesSize, char** dictionary, int dictionarySize, int* returnSize) {
    char** res = (char**)malloc(queriesSize * sizeof(char*));
    int count = 0;
    int wordLen = strlen(queries[0]);

    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < dictionarySize; j++) {
            int diff = 0;
            for (int k = 0; k < wordLen; k++) {
                if (queries[i][k] != dictionary[j][k]) {
                    diff++;
                }
                // Optimization: stop if we already exceed 2 edits
                if (diff > 2) break;
            }

            if (diff <= 2) {
                res[count] = (char*)malloc((wordLen + 1) * sizeof(char));
                strcpy(res[count], queries[i]);
                count++;
                break; 
            }
        }
    }

    *returnSize = count;
    return res;
}