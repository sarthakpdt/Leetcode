// Structure to store the original value and its original index
typedef struct {
    int val;
    int id;
} Node;

// Comparator function to sort nodes by value
int compareNodes(const void* a, const void* b) {
    Node* n1 = (Node*)a;
    Node* n2 = (Node*)b;
    if (n1->val != n2->val) {
        return (n1->val < n2->val) ? -1 : 1;
    }
    return (n1->id < n2->id) ? -1 : 1;
}

int* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // 1. Sort the elements while preserving their original indices
    Node* sorted = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        sorted[i].val = nums[i];
        sorted[i].id = i;
    }
    qsort(sorted, n, sizeof(Node), compareNodes);

    // 2. Map original indices to their new positions in the sorted array
    int* pos = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pos[sorted[i].id] = i;
    }

    // 3. Compute the furthest right index reachable from each position in 1 step
    int* right = (int*)malloc(n * sizeof(int));
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && sorted[j].val <= sorted[i].val + maxDiff) {
            j++;
        }
        right[i] = j - 1; // j - 1 is the maximum index satisfying the condition
    }

    // 4. Build the Binary Lifting table
    int LOG = 18; // 2^17 = 131,072 > 10^5
    int** up = (int**)malloc(LOG * sizeof(int*));
    for (int k = 0; k < LOG; k++) {
        up[k] = (int*)malloc(n * sizeof(int));
    }

    // Base case: 2^0 = 1 step
    for (int i = 0; i < n; i++) {
        up[0][i] = right[i];
    }

    // Dynamic programming to compute 2^k steps
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i < n; i++) {
            up[k][i] = up[k - 1][up[k - 1][i]];
        }
    }

    // 5. Answer each query
    int* answer = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];
        int p1 = pos[u];
        int p2 = pos[v];

        // If it's the same node, distance is 0
        if (p1 == p2) {
            answer[i] = 0;
            continue;
        }
        
        // Ensure p1 is always the smaller sorted index
        if (p1 > p2) {
            int temp = p1;
            p1 = p2;
            p2 = temp;
        }

        int steps = 0;
        // Jump as far as possible without exceeding p2
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][p1] < p2) {
                steps += (1 << k);
                p1 = up[k][p1];
            }
        }

        // If one more step can reach or exceed p2, it's reachable
        if (up[0][p1] >= p2) {
            answer[i] = steps + 1;
        } else {
            answer[i] = -1; // Disconnected components
        }
    }

    // Free dynamically allocated memory
    free(sorted);
    free(pos);
    free(right);
    for (int k = 0; k < LOG; k++) {
        free(up[k]);
    }
    free(up);

    return answer;
}
