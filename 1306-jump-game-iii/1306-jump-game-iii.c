bool canReach(int* arr, int arrSize, int start) {
    if(start<0 || start>=arrSize || arr[start]<0){
        return 0;
    }
    if (arr[start]==0){
        return 1;
    }
    int jump=arr[start];
    arr[start]=-arr[start];
    int a=canReach(arr,arrSize,jump+start);
    int b=canReach(arr,arrSize,start-jump);
    return a||b;
}