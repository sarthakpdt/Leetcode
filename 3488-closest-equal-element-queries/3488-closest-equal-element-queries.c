#include <stdlib.h>
#include <math.h>

typedef struct {
    int* indices;
    int count;
    int capacity;
} IndexList;

int* solveQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    
    // Find max value for the index map (assuming values up to 10^6 per constraints)
    int maxVal = 0;
    for(int i = 0; i < numsSize; i++) if(nums[i] > maxVal) maxVal = nums[i];
    
    // Create an array of pointers to store indices for each value
    IndexList* map = (IndexList*)calloc(maxVal + 1, sizeof(IndexList));
    
    // First pass: Store all indices for each value
    for(int i = 0; i < numsSize; i++) {
        int v = nums[i];
        if(map[v].capacity == 0) {
            map[v].capacity = 2;
            map[v].indices = (int*)malloc(2 * sizeof(int));
        } else if(map[v].count == map[v].capacity) {
            map[v].capacity *= 2;
            map[v].indices = (int*)realloc(map[v].indices, map[v].capacity * sizeof(int));
        }
        map[v].indices[map[v].count++] = i;
    }

    // Second pass: Process queries using binary search on the index lists
    for(int i = 0; i < queriesSize; i++) {
        int q_idx = queries[i];
        int val = nums[q_idx];
        IndexList* list = &map[val];

        if(list->count <= 1) {
            ans[i] = -1;
            continue;
        }

        // Binary Search to find the position of q_idx in the sorted list of indices
        int low = 0, high = list->count - 1, pos = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(list->indices[mid] == q_idx) {
                pos = mid;
                break;
            }
            if(list->indices[mid] < q_idx) low = mid + 1;
            else high = mid - 1;
        }

        // Neighbors are at pos-1 and pos+1
        int prev_idx = (pos == 0) ? list->indices[list->count - 1] : list->indices[pos - 1];
        int next_idx = (pos == list->count - 1) ? list->indices[0] : list->indices[pos + 1];

        // Calculate circular distances for both neighbors
        int d1 = abs(q_idx - prev_idx);
        if(numsSize - d1 < d1) d1 = numsSize - d1;
        
        int d2 = abs(q_idx - next_idx);
        if(numsSize - d2 < d2) d2 = numsSize - d2;

        ans[i] = (d1 < d2) ? d1 : d2;
    }

    // Clean up
    for(int i = 0; i <= maxVal; i++) if(map[i].indices) free(map[i].indices);
    free(map);

    return ans;
}