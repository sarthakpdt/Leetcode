#include <stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int n = matColSize[0]; // Number of columns
    
    // We only need to check the effective shift
    int shift = k % n;
    
    // If the effective shift is 0, the matrix will always be identical
    if (shift == 0) return true;

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < n; j++) {
            // Check if current element matches the element 'shift' positions away
            // This works for both left and right cyclic shifts because 
            // if a row is periodic relative to 'k', it remains identical.
            if (mat[i][j] != mat[i][(j + shift) % n]) {
                return false;
            }
        }
    }
    
    return true;
}