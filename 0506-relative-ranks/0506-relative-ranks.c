// Structure to pair each score with its original index
typedef struct {
    int score;
    int index;
} Athlete;

// Comparison function to sort athletes by score in descending order
int compare(const void* a, const void* b) {
    return ((Athlete*)b)->score - ((Athlete*)a)->score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    
    // Allocate memory for the array of strings to be returned
    char** result = (char**)malloc(scoreSize * sizeof(char*));
    if (result == NULL) return NULL;
    
    // Create and populate the array of structures
    Athlete* athletes = (Athlete*)malloc(scoreSize * sizeof(Athlete));
    if (athletes == NULL) {
        free(result);
        return NULL;
    }
    
    for (int i = 0; i < scoreSize; i++) {
        athletes[i].score = score[i];
        athletes[i].index = i;
    }
    
    // Sort athletes in descending order of their scores
    qsort(athletes, scoreSize, sizeof(Athlete), compare);
    
    // Assign ranks based on sorted order
    for (int i = 0; i < scoreSize; i++) {
        int originalIdx = athletes[i].index;
        
        // Allocate a small buffer for each string (max string is "Silver Medal" or a number up to 10000)
        result[originalIdx] = (char*)malloc(15 * sizeof(char));
        
        if (i == 0) {
            sprintf(result[originalIdx], "Gold Medal");
        } else if (i == 1) {
            sprintf(result[originalIdx], "Silver Medal");
        } else if (i == 2) {
            sprintf(result[originalIdx], "Bronze Medal");
        } else {
            // Placement is 1-indexed, so we add 1 to the 0-indexed loop variable `i`
            sprintf(result[originalIdx], "%d", i + 1);
        }
    }
    
    // Free the temporary tracking array
    free(athletes);
    
    return result;
}
