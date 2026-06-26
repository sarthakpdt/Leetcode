int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int MOD=1000000007;
    for (int i=0;i<queriesSize;i++){
        int last=queries[i][3];
        int k=queries[i][0];
        int l=queries[i][1];
        int m=queries[i][2];
        while(k<=l){
            nums[k]=((long long) nums[k]*last)%MOD;
            k+=m;
        }
    }
    int res=0;
    for (int i=0;i<numsSize;i++){
        res^=nums[i];
    }
    return res;
}