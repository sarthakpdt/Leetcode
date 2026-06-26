/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    *returnSize=numsSize;
    int lcount=0;
    int rcount=0;
    for (int i=0;i<numsSize;i++){
        if (nums[i]<pivot){
            lcount++;
        }
        else{
            rcount++;
        }
    }
    int *larray=(int *)malloc(lcount*sizeof(int));
    int *rarray=(int *)malloc(rcount*sizeof(int));
    int *farray=(int *)malloc(numsSize*sizeof(int));
    int li=0;
    int ri=0;
    for (int i=0;i<numsSize;i++){
        int a=nums[i];
        if (a<pivot){
            larray[li]=a;
            li++;
        }
    }
    for (int i=0;i<numsSize;i++){
        int a=nums[i];
        if (a==pivot){
            rarray[ri]=a;
            ri++;
        }
    }
    for (int i=0;i<numsSize;i++){
        int a=nums[i];
        if (a>pivot){
            rarray[ri]=a;
            ri++;
        }
    }
    for (int i=0;i<lcount;i++){
        farray[i]=larray[i];
    }
    for (int j=0;j<rcount;j++){
        farray[lcount+j]=rarray[j];
    }
    free(larray);
    free(rarray);
    return farray;
}