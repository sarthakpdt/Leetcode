void swap(int arr[],int i,int j){
	int temp=arr[i]; 
	arr[i]=arr[j]; 
	arr[j]=temp; 
}
void bubblesort(int arr[],int n){
	int flag;
	for (int i=0;i<n-1;i++){
		flag=0;
		for (int j=0;j<n-i-1;j++){
			if (arr[j]>arr[j+1]){
				swap(arr,j,j+1);
				flag=1;
			}
		}
		if (flag==0){
			break;
		}
	}
}
int minimumCost(int* cost, int costSize) {
    bubblesort(cost,costSize);
    int res=0;
    int count=0;
    for (int i=costSize-1;i>=0;i--){
        if (count%3!=2){
            res+=cost[i];
        }
        count++;
    }
    return res;
}