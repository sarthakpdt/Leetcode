long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    int n = numsSize;
    // represents the occurrence count of prefix sums -n, -(n-1), ..., 0, 1,
    // ..., n, with index offset by n.
    int* pre = (int*)calloc(n * 2 + 1, sizeof(int));
    pre[n] = 1;
    int cnt = n;
    long long ans = 0, presum = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == target) {
            presum += pre[cnt];
            ++cnt;
            ++pre[cnt];
        } else {
            --cnt;
            presum -= pre[cnt];
            ++pre[cnt];
        }
        ans += presum;
    }
    free(pre);
    return ans;
}