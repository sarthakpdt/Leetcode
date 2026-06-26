int totalSteps(int* nums, int numsSize) {
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    int maxSteps = 0;

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 0;
        while (top >= 0 && nums[stack[top]] <= nums[i]) {
            if (dp[stack[top]] > dp[i]) {
                dp[i] = dp[stack[top]];
            }
            top--;
        }
        if (top >= 0) {
            dp[i]++;
        } else {
            dp[i] = 0;
        }
        if (dp[i] > maxSteps) {
            maxSteps = dp[i];
        }
        top++;
        stack[top] = i;
    }

    free(stack);
    free(dp);
    return maxSteps;
}