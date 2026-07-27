int maxProduct(int* nums, int numsSize) {
    int *array=(int *)malloc(numsSize*numsSize*sizeof(int));
    int l=0;
    for (int i=0;i<numsSize;i++){
        for (int j=i+1;j<numsSize;j++){
            array[l++]=(nums[i]-1)*(nums[j]-1);
        }
    }
    int max=array[0];
    for (int k=0;k<l;k++){
        int a=array[k];
        if (a>max){
            max=a;
        }
    }
    return max;
}