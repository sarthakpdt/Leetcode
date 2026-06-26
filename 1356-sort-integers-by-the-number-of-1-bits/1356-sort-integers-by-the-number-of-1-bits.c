/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void swap(int *res,int count[],int i,int j){
    int temp=res[i];
    res[i]=res[j];
    res[j]=temp;
    int tempc=count[i];
    count[i]=count[j];
    count[j]=tempc;
}
void sort(int *res,int count[],int n){
    int flag;
    for (int i=0;i<n-1;i++){
        flag=0;
        for (int j=0;j<n-i-1;j++){
            if (count[j]>count[j+1]|| (count[j] == count[j + 1] && res[j] > res[j + 1])){
                swap(res,count,j,j+1);
                flag=1;
            }
        }
        if (flag==0){
            break;
        }
    }
}
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize=arrSize;
    int* res=(int*)malloc(arrSize*sizeof(int));
    int count[arrSize];
    for (int i=0;i<arrSize;i++){
        res[i]=arr[i];
        int c=0;
        int temp=arr[i];
        while(temp>0){
            if (temp%2==1){
                c++;
            }
            temp=temp/2;
        }
        count[i]=c;
    }
    sort(res,count,arrSize);
    return res;
}

