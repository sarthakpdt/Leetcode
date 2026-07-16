long long gcd(long long a,long long b){
    while(b!=0){
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
void mergesort(int arr[],int left,int right){
	if (left<right){
		int mid=left+(right-left)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		int n1=mid-left+1;
		int n2=right-mid;
		int larr[n1];
		int rarr[n2];
		for (int i=0;i<n1;i++){
			larr[i]=arr[left+i];
		}
		for (int i=0;i<n2;i++){
			rarr[i]=arr[mid+i+1];
		}
		int i=0;
		int j=0;
		int k=left;
		for (;i<n1 && j<n2;k++){
			if (larr[i]<rarr[j]){
				arr[k]=larr[i];
				i++;
			}
			else{
				arr[k]=rarr[j];
				j++;
			}
		}
		for (;i<n1;i++,k++){
			arr[k]=larr[i];
		}
		for (;j<n2;j++,k++){
			arr[k]=rarr[j];
		}
	}
}
long long gcdSum(int* nums, int numsSize) {
    int pre[numsSize];
    int mx=nums[0];
    for(int i=0;i<numsSize;i++){
        mx=max(mx,nums[i]);
        pre[i]=gcd(nums[i],mx);
    }
    mergesort(pre,0,numsSize-1);
    long long ans=0;
    int left=0;
    int right=numsSize-1;
    while(left<right){
        ans+=gcd(pre[left],pre[right]);
        left++;
        right--;
    }
    return ans;
}