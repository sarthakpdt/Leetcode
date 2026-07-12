/**
 * Note: The returned array must be malloced, assume caller calls free().
 */ 
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
int binarySearch(int arr[], int size, int target){
    int low=0;
    int high=size-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    return -1;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize){

    *returnSize=arrSize;

    if(arrSize==0){
        return NULL;
    }

    int *copy=(int *)malloc(arrSize*sizeof(int));

    for(int i=0;i<arrSize;i++){
        copy[i]=arr[i];
    }

    mergesort(copy,0,arrSize-1);

    int *values=(int *)malloc(arrSize*sizeof(int));
    int *ranks=(int *)malloc(arrSize*sizeof(int));

    int m=0;
    int rank=1;

    values[m]=copy[0];
    ranks[m]=1;
    m++;

    for(int i=1;i<arrSize;i++){
        if(copy[i]!=copy[i-1]){
            rank++;
            values[m]=copy[i];
            ranks[m]=rank;
            m++;
        }
    }

    int *ans=(int *)malloc(arrSize*sizeof(int));

    for(int i=0;i<arrSize;i++){
        int idx=binarySearch(values,m,arr[i]);
        ans[i]=ranks[idx];
    }

    free(copy);
    free(values);
    free(ranks);

    return ans;
}