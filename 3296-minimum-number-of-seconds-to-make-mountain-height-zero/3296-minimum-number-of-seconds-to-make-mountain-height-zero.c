#include <math.h>
#include <stdbool.h>

bool canFinish(long long t,int mH,int*wT,int s){
    long long totalH=0;
    for(int i=0;i<s;i++){
        double val=(double)t/wT[i];
        long long x=(long long)((-1.0+sqrt(1.0+8.0*val))/2.0);
        totalH+=x;
        if(totalH>=mH)return true;
    }
    return totalH>=mH;
}

long long minNumberOfSeconds(int mountainHeight,int*workerTimes,int workerTimesSize){
    long long low=0;
    long long high=1e16;
    long long ans=high;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(canFinish(mid,mountainHeight,workerTimes,workerTimesSize)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}