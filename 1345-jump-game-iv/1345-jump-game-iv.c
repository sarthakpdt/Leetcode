#include <stdlib.h>
#include <stdbool.h>

// Helper structure to group identical values
typedef struct {
    int val;
    int idx;
} Node;

int compareNodes(const void* a, const void* b) {
    Node* n1 = (Node*)a;
    Node* n2 = (Node*)b;
    if (n1->val != n2->val) return (n1->val > n2->val) - (n1->val < n2->val);
    return n1->idx - n2->idx;
}

int minJumps(int* arr, int arrSize) {
    if (arrSize <= 1) return 0;

    // 1. Create a sorted map of values to track where identical values live
    Node* nodes = (Node*)malloc(arrSize * sizeof(Node));
    for (int i = 0; i < arrSize; i++) {
        nodes[i].val = arr[i];
        nodes[i].idx = i;
    }
    qsort(nodes, arrSize, sizeof(Node), compareNodes);

    // Head and Tail pointers for quick binary searching of identical groups
    int* groupStart = (int*)malloc(arrSize * sizeof(int));
    int* groupEnd = (int*)malloc(arrSize * sizeof(int));
    
    // Pre-calculate starting and ending boundaries for each value group
    for (int i = 0; i < arrSize; ) {
        int j = i;
        while (j < arrSize && nodes[j].val == nodes[i].val) j++;
        for (int k = i; k < j; k++) {
            groupStart[nodes[k].idx] = i;
            groupEnd[nodes[k].idx] = j;
        }
        i = j;
    }

    // 2. Set up BFS Tracking (Identical to your Jump Game/Street path queues)
    int* queue = (int*)malloc(arrSize * sizeof(int));
    int* steps = (int*)malloc(arrSize * sizeof(int));
    bool* visited = (bool*)calloc(arrSize, sizeof(bool));
    bool* groupVisited = (bool*)calloc(arrSize, sizeof(bool)); // Tracks if a value group was cleared
    
    int head = 0, tail = 0;
    
    queue[tail] = 0;
    steps[tail] = 0;
    tail++;
    visited[0] = true;

    while (head < tail) {
        int currIdx = queue[head];
        int currSteps = steps[head];
        head++;

        // Destination reached!
        if (currIdx == arrSize - 1) {
            free(nodes); free(groupStart); free(groupEnd);
            free(queue); free(steps); free(visited); free(groupVisited);
            return currSteps;
        }

        // Option 1: Jump to i + 1
        if (currIdx + 1 < arrSize && !visited[currIdx + 1]) {
            visited[currIdx + 1] = true;
            queue[tail] = currIdx + 1;
            steps[tail] = currSteps + 1;
            tail++;
        }

        // Option 2: Jump to i - 1
        if (currIdx - 1 >= 0 && !visited[currIdx - 1]) {
            visited[currIdx - 1] = true;
            queue[tail] = currIdx - 1;
            steps[tail] = currSteps + 1;
            tail++;
        }

        // Option 3: Jump to all matching values arr[i] == arr[j]
        int startPos = groupStart[currIdx];
        if (!groupVisited[startPos]) { // Only process this identical number pool once!
            int endPos = groupEnd[currIdx];
            for (int k = startPos; k < endPos; k++) {
                int targetIdx = nodes[k].idx;
                if (!visited[targetIdx]) {
                    visited[targetIdx] = true;
                    queue[tail] = targetIdx;
                    steps[tail] = currSteps + 1;
                    tail++;
                }
            }
            groupVisited[startPos] = true; // Clear out pool to ensure O(N) speed
        }
    }

    return 0;
}