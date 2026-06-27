/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int *array=(int *)malloc(numsSize*sizeof(int));
    int even=0;
    int odd=1;
    for (int i=0;i<numsSize;i++){
        if (nums[i]%2==0){
            array[even]=nums[i];
            even+=2;
        }
        else{
            array[odd]=nums[i];
            odd+=2;
        }
    }
    return array;
}