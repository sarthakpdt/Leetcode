int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Tracks the position for the next valid element

    for (int i = 0; i < numsSize; i++) {
        // If the current element is NOT the one we want to remove
        if (nums[i] != val) {
            nums[k] = nums[i]; // Move it to the front of the array
            k++;               // Move the write pointer forward
        }
    }

    // k automatically equals the total number of valid elements
    return k; 
}
