int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        
        if (nums[mid] == target)
            return mid;        
        
        // Condition 1: Check if the left half is normally sorted
        if (nums[low] <= nums[mid]) {
            // Is target inside this sorted left half?
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1; // Search left
            else
                low = mid + 1;  // Search right
        }       
        // Condition 2: The right half must be the sorted one
        else {
            // Is target inside this sorted right half?
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;  // Search right
            else
                high = mid - 1; // Search left
        }     
    }
    return -1; 
}
