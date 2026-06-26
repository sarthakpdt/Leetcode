#include <stdbool.h>
#include <stdlib.h>

bool is_connected(int r, int c, int nr, int nc, int** grid, int m, int n) {
    if (nr < 0 || nr >= m || nc < 0 || nc >= n) return false;
    
    int current = grid[r][c];
    int next = grid[nr][nc];
    
    // Check if we are moving Right
    if (nr == r && nc == c + 1) {
        if ((current == 1 || current == 4 || current == 6) && 
            (next == 1 || next == 3 || next == 5)) return true;
    }
    // Check if we are moving Left
    if (nr == r && nc == c - 1) {
        if ((current == 1 || current == 3 || current == 5) && 
            (next == 1 || next == 4 || next == 6)) return true;
    }
    // Check if we are moving Down
    if (nr == r + 1 && nc == c) {
        if ((current == 2 || current == 3 || current == 4) && 
            (next == 2 || next == 5 || next == 6)) return true;
    }
    // Check if we are moving Up
    if (nr == r - 1 && nc == c) {
        if ((current == 2 || current == 5 || current == 6) && 
            (next == 2 || next == 3 || next == 4)) return true;
    }
    
    return false;
}

bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) visited[i] = (bool*)calloc(n, sizeof(bool));
    
    // Simple BFS Queue
    int* queueR = (int*)malloc(m * n * sizeof(int));
    int* queueC = (int*)malloc(m * n * sizeof(int));
    int head = 0, tail = 0;
    
    queueR[tail] = 0;
    queueC[tail++] = 0;
    visited[0][0] = true;
    
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    
    while (head < tail) {
        int r = queueR[head];
        int c = queueC[head++];
        
        if (r == m - 1 && c == n - 1) {
            // Found the exit, cleanup memory
            for (int i = 0; i < m; i++) free(visited[i]);
            free(visited); free(queueR); free(queueC);
            return true;
        }
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                if (is_connected(r, c, nr, nc, grid, m, n)) {
                    visited[nr][nc] = true;
                    queueR[tail] = nr;
                    queueC[tail++] = nc;
                }
            }
        }
    }
    
    for (int i = 0; i < m; i++) free(visited[i]);
    free(visited); free(queueR); free(queueC);
    return false;
}