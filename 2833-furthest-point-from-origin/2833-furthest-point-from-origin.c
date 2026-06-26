#include <stdlib.h>
#include <string.h>

int furthestDistanceFromOrigin(char* moves) {
    int L = 0, R = 0, underscore = 0;
    
    for (int i = 0; moves[i] != '\0'; i++) {
        if (moves[i] == 'L') L++;
        else if (moves[i] == 'R') R++;
        else underscore++;
    }
    
    // The trick: |L - R| gives the base displacement, 
    // then add all underscores to maximize that direction.
    int diff = L - R;
    if (diff < 0) diff = -diff; // Absolute value
    
    return diff + underscore;
}















































































