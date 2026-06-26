#include <string.h>
#include <stdlib.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    
    // Allocate memory for the queues
    int* radiantQueue = (int*)malloc(n * sizeof(int));
    int* direQueue = (int*)malloc(n * sizeof(int));
    
    int rHead = 0, rTail = 0;
    int dHead = 0, dTail = 0;
    
    // Populate initial indices
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            radiantQueue[rTail++] = i;
        } else {
            direQueue[dTail++] = i;
        }
    }
    
    // Simulate the rounds
    while (rHead < rTail && dHead < dTail) {
        int rIndex = radiantQueue[rHead++];
        int dIndex = direQueue[dHead++];
        
        // The senator with the smaller index bans the other
        if (rIndex < dIndex) {
            radiantQueue[rTail++] = rIndex + n; // Re-queue for next round
        } else {
            direQueue[dTail++] = dIndex + n;    // Re-queue for next round
        }
    }
    
    // Clean up memory
    free(radiantQueue);
    free(direQueue);
    
    // If Radiant's queue still has active senators, Radiant wins
    return (rHead < rTail) ? "Radiant" : "Dire";
}
