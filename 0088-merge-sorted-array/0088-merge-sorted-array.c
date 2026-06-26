void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=m-1; 
    int j=n-1; 
    int k=m+n-1; 
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--]=nums1[i--];
        } 
        else{
            nums1[k--]=nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}
void mergesort(int *nums1,int right,int left){
    if (left<right){
        int mid=left+(right-left)/2;
        mergesort(nums1,left,mid);
        mergesort(nums1,mid+1,right);
        int n1=mid-left+1;
        int n2=right-mid;
        int larr[n1];
        int rarr[n2];
        for (int i=0;i<n1;i++){
            larr[i]=nums1[left+i];
        }
        for (int i=0;i<n2;i++){
            rarr[i]=nums1[mid+i+1];
        }
        int j=0;
        int i=0;
        int k=left;
        for (;i<n1 && j<n2;k++){
            if (larr[i]<rarr[j]){
                nums1[k]=larr[i];
                i++;
            }
            else{
                nums1[k]=rarr[j];
                j++;
            }
        }
        for (;i<n1;i++,k++){
            nums1[k]=larr[i];
        }
        for (;j<n2;j++,k++){
            nums1[k]=rarr[j];
        }
    }
}