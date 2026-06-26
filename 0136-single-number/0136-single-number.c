int singleNumber(int* nums, int numsSize) {
    int res = 0; // Initialize result
    for (int i = 0; i < numsSize; i++) {
        res ^= nums[i]; // XOR every number with res
    }
    return res; // The result will be the single number
}
