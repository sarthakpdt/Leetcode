#include <stdbool.h>
#include <stdlib.h>

bool dfs(int r, int c, int pr, int pc, char target, char** grid, int m, int n, int** visited) {
    visited[r][c] = 1;
    
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == target) {
            if (visited[nr][nc]) {
                // If visited and not the parent, we found a cycle
                if (nr != pr || nc != pc) return true;
            } else {
                if (dfs(nr, nc, r, c, target, grid, m, n, visited)) return true;
            }
        }
    }
    return false;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Allocate visited array
    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)calloc(n, sizeof(int));
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, -1, -1, grid[i][j], grid, m, n, visited)) {
                    // Free memory before returning
                    for (int k = 0; k < m; k++) free(visited[k]);
                    free(visited);
                    return true;
                }
            }
        }
    }
    
    // Free memory
    for (int i = 0; i < m; i++) free(visited[i]);
    free(visited);
    return false;
}