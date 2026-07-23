int uniqueXorTriplets(int* nums,int numsSize){
    if(numsSize==1){
        return 1;
    }

    if(numsSize==2){
        return 2;
    }

    int ans=1;

    while(ans<=numsSize){
        ans=ans*2;
    }

    return ans;
}