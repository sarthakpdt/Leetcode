#include <stdbool.h>

bool isEqual(int** mat, int** target, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] != target[i][j])
                return false;
        }
    }
    return true;
}

void rotate(int** mat, int n) {
    int temp[n][n];

    // rotate 90 degree clockwise
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[j][n - i - 1] = mat[i][j];
        }
    }

    // copy back to mat
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mat[i][j] = temp[i][j];
        }
    }
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    
    for(int k = 0; k < 4; k++) {
        if(isEqual(mat, target, matSize))
            return true;
        
        rotate(mat, matSize);
    }
    
    return false;
}