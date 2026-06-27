int threeSumMulti(int* arr,int arrSize,int target){
    const int MOD=1000000007;
    long long ans=0;
    long long freq[101]={0};

    for(int i=0;i<arrSize;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<=100;i++){
        if(freq[i]==0) continue;

        for(int j=i;j<=100;j++){
            if(freq[j]==0) continue;

            int k=target-i-j;

            if(k<0||k>100||k<j||freq[k]==0) continue;

            if(i==j&&j==k){
                ans+=freq[i]*(freq[i]-1)*(freq[i]-2)/6;
            }
            else if(i==j){
                ans+=(freq[i]*(freq[i]-1)/2)*freq[k];
            }
            else if(j==k){
                ans+=freq[i]*(freq[j]*(freq[j]-1)/2);
            }
            else{
                ans+=freq[i]*freq[j]*freq[k];
            }

            ans%=MOD;
        }
    }

    return ans;
}