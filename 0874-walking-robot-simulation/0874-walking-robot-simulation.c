#include <stdlib.h>

// Comparison function for qsort: Sort by X, then by Y
int compareObstacles(const void* a, const void* b) {
    int* obsA = *(int**)a;
    int* obsB = *(int**)b;
    if (obsA[0] != obsB[0]) return obsA[0] - obsB[0];
    return obsA[1] - obsB[1];
}

// Binary search to see if (targetX, targetY) is an obstacle
int isBlocked(int targetX, int targetY, int** obstacles, int obstaclesSize) {
    int left = 0, right = obstaclesSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (obstacles[mid][0] == targetX && obstacles[mid][1] == targetY) {
            return 1; // Found an obstacle
        }
        if (obstacles[mid][0] < targetX || (obstacles[mid][0] == targetX && obstacles[mid][1] < targetY)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0; // No obstacle
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    // 1. Sort obstacles once at the start
    if (obstaclesSize > 0) {
        qsort(obstacles, obstaclesSize, sizeof(int*), compareObstacles);
    }

    int x = 0, y = 0, direction = 0; // 0:N, 1:E, 2:S, 3:W
    int maxDistSq = 0;

    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] == -2) { // Left
            if (direction == 0) direction = 3;
            else if (direction == 1) direction = 0;
            else if (direction == 2) direction = 1;
            else direction = 2;
        } else if (commands[i] == -1) { // Right
            if (direction == 0) direction = 1;
            else if (direction == 1) direction = 2;
            else if (direction == 2) direction = 3;
            else direction = 0;
        } else {
            for (int k = 0; k < commands[i]; k++) {
                int nextX = x, nextY = y;
                
                if (direction == 0) nextY++;
                else if (direction == 1) nextX++;
                else if (direction == 2) nextY--;
                else nextX--;

                // 2. Use the fast binary search instead of a full loop
                if (isBlocked(nextX, nextY, obstacles, obstaclesSize)) {
                    break; 
                }

                x = nextX;
                y = nextY;
                int distSq = x * x + y * y;
                if (distSq > maxDistSq) maxDistSq = distSq;
            }
        }
    }
    return maxDistSq;
}