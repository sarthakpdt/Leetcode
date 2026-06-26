#include <stdlib.h>

typedef struct {
    int val;
    int index;
} Node;

int compare(const void* a, const void* b) {
    Node* n1 = (Node*)a;
    Node* n2 = (Node*)b;
    if (n1->val != n2->val) return n1->val - n2->val;
    return n1->index - n2->index;
}

long long* distance(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    long long* arr = (long long*)calloc(numsSize, sizeof(long long));
    Node* nodes = (Node*)malloc(numsSize * sizeof(Node));

    for (int i = 0; i < numsSize; i++) {
        nodes[i].val = nums[i];
        nodes[i].index = i;
    }

    // Group identical numbers together by sorting
    qsort(nodes, numsSize, sizeof(Node), compare);

    int i = 0;
    while (i < numsSize) {
        int j = i;
        while (j < numsSize && nodes[j].val == nodes[i].val) j++;
        
        int count = j - i;
        long long total_sum = 0;
        for (int k = i; k < j; k++) total_sum += nodes[k].index;

        long long prefix_sum = 0;
        for (int k = i; k < j; k++) {
            int idx = nodes[k].index;
            int left_count = k - i;
            int right_count = j - 1 - k;

            long long left_dist = (long long)left_count * idx - prefix_sum;
            long long right_dist = (total_sum - prefix_sum - idx) - (long long)right_count * idx;

            arr[idx] = left_dist + right_dist;
            prefix_sum += idx;
        }
        i = j;
    }

    free(nodes);
    return arr;
}