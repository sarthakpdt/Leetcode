/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int *arr=(int *)malloc(sizeof(int)*101);
    int min=nums[0];
    int max=nums[0];
    for (int i=1;i<numsSize;i++){
        int a=nums[i];
        if (max<a){
            max=a;
        }
        if (a<min){
            min=a;
        }
    }
    int l=0;
    for (int i=min;i<=max;i++){
        int found=0;
        for (int j=0;j<numsSize;j++){
            if (i==nums[j]){
                found=1;
                break;
            }
        }
        if (!found){
            arr[l++]=i;
        }
    }
    *returnSize=l;
    return arr;
}