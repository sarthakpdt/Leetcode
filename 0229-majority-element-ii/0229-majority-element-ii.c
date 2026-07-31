/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
int* majorityElement(int* nums,int numsSize,int* returnSize){
    qsort(nums,numsSize,sizeof(int),compare);
    int *res=(int *)malloc(2*sizeof(int));
    *returnSize=0;
    int count=1;
    for(int i=1;i<=numsSize;i++){
        if(i<numsSize && nums[i]==nums[i-1]){
            count++;
        }
        else{
            if(count>numsSize/3){
                res[*returnSize]=nums[i-1];
                (*returnSize)++;
            }
            count=1;
        }
    }
    return res;
}