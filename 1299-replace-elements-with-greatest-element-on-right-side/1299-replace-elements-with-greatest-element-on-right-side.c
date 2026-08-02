/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr,int arrSize,int* returnSize){
    int *res=(int *)malloc(arrSize*sizeof(int));
    int max=-1;
    for(int i=arrSize-1;i>=0;i--){
        res[i]=max;
        if(arr[i]>max){
            max=arr[i];
        }
    }
    *returnSize=arrSize;
    return res;
}