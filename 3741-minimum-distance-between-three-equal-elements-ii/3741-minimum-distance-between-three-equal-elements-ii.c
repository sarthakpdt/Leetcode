int minimumDistance(int* nums, int numsSize) {
    int* p1=(int*)malloc((numsSize+1)*sizeof(int));
    int* p2=(int*)malloc((numsSize+1)*sizeof(int));
    for(int i=0;i<=numsSize;i++) p1[i]=p2[i]=-1;
    long min_d=LONG_MAX;
    int f=0;
    for(int i=0;i<numsSize;i++){
        int v=nums[i];
        if(p1[v]!=-1){
            long d=2L*(i-p1[v]);
            if(d<min_d) min_d=d;
            f=1;
        }
        p1[v]=p2[v];
        p2[v]=i;
    }
    free(p1);
    free(p2);
    return f?(int)min_d:-1;
}