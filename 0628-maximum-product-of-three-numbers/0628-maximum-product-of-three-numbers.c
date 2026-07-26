#include <stdlib.h>

int compare(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}

int maximumProduct(int* nums,int numsSize){

    qsort(nums,numsSize,sizeof(int),compare);

    int p1=nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];

    int p2=nums[0]*nums[1]*nums[numsSize-1];

    if(p1>p2){
        return p1;
    }

    return p2;
}