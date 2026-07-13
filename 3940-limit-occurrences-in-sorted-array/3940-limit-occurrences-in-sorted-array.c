/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* limitOccurrences(int* nums, int numsSize, int k, int* returnSize) {
    int *array=(int *)malloc(sizeof(int)*numsSize);
    int count=1;
    int j=0;
    array[j++]=nums[0];
    for (int i=1;i<numsSize;i++){
        if (nums[i]==nums[i-1]){
            count++;
        }
        else{
            count=1;
        }
        if(count<=k){
            array[j]=nums[i];
            j++;
        }
    }
    *returnSize=j;
    return array;
}