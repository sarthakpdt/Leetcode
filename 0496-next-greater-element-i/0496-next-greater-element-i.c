/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* arr = (int*)malloc(nums1Size * sizeof(int));
    *returnSize=nums1Size;
    for (int i=0;i<nums1Size;i++){
        arr[i]=-1;
        for (int j=0;j<nums2Size;j++){
            if(nums1[i]==nums2[j]){
                for (int k=j+1;k<nums2Size;k++){
                    if (nums2[k]>nums1[i]){
                        arr[i]=nums2[k];
                        break;
                    }
                }
                break;
            }
        }
    }
    return arr;
}