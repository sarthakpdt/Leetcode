int shortestSubarray(int* nums, int numsSize, int k) {
    // 1. Create prefix sum array using long long to prevent integer overflow
    long long* prefixSum = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    // 2. Setup our Deque array (stores indices)
    int* deque = (int*)malloc((numsSize + 1) * sizeof(int));
    int head = 0, tail = 0; // head is front, tail is back
    
    int minLen = INT_MAX;

    // 3. Scan through the prefix sums
    for (int i = 0; i <= numsSize; i++) {
        
        // Check if the current window sum is >= k
        while (tail > head && prefixSum[i] - prefixSum[deque[head]] >= k) {
            int currentLen = i - deque[head];
            if (currentLen < minLen) {
                minLen = currentLen;
            }
            head++; // Shrink window from left (pop front)
        }

        // Maintain monotonicity: remove elements from back that are larger than current
        while (tail > head && prefixSum[i] <= prefixSum[deque[tail - 1]]) {
            tail--; // pop back
        }

        // Push current index to the back of the deque
        deque[tail] = i;
        tail++;
    }

    // Clean up memory
    free(prefixSum);
    free(deque);

    // If minLen wasn't updated, it means no valid subarray was found
    return (minLen == INT_MAX) ? -1 : minLen;
}