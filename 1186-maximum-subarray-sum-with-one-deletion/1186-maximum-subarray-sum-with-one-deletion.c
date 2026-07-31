int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int maximumSum(int* arr,int arrSize){
    if(arrSize==1){
        return arr[0];
    }
    int noskip=arr[0];
    int skip=arr[0];
    int maxsum=arr[0];
    for(int i=1;i<arrSize;i++){
        int prev=noskip;
        skip=max(prev,skip+arr[i]);
        noskip=max(noskip+arr[i],arr[i]);
        if(noskip>maxsum){
            maxsum=noskip;
        }
        if(skip>maxsum){
            maxsum=skip;
        }
    }
    return maxsum;
}