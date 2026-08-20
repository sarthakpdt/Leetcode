/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int *arr1=(int *)malloc(sizeof(int)*101);
    int *arr2=(int *)malloc(sizeof(int)*101);
    arr1[0]=nums[0];
    arr2[0]=nums[1];
    int j=1;
    int k=1;
    for (int i=2;i<numsSize;i++){
        if (arr1[j-1]>arr2[k-1]){
            arr1[j++]=nums[i];
        }
        else{
            arr2[k++]=nums[i];
        }
    }
    int size=j+k;
    int *res=(int *)malloc(sizeof(int)*size);
    for (int i=0;i<j;i++){
        res[i]=arr1[i];
    }
    for (int i=0;i<k;i++){
        res[j+i]=arr2[i];
    }
    *returnSize=size;
    return res;
}