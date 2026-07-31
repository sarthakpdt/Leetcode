#define MOD 1000000007
long long max(long long a,long long b){
    if(a>b){
        return a;
    }
    return b;
}
int maxSum(int* nums1,int nums1Size,int* nums2,int nums2Size){
    long long total=0;
    long long sum1=0;
    long long sum2=0;
    int i=0;
    int j=0;
    while(i<nums1Size && j<nums2Size){
        if(nums1[i]<nums2[j]){
            sum1+=nums1[i];
            i++;
        }
        else if(nums1[i]>nums2[j]){
            sum2+=nums2[j];
            j++;
        }
        else{
            total+=max(sum1,sum2)+nums1[i];
            sum1=0;
            sum2=0;
            i++;
            j++;
        }
    }
    while(i<nums1Size){
        sum1+=nums1[i];
        i++;
    }
    while(j<nums2Size){
        sum2+=nums2[j];
        j++;
    }
    total+=max(sum1,sum2);
    return total%MOD;
}