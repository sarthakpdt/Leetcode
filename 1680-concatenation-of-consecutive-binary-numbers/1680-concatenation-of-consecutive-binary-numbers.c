int concatenatedBinary(int n){
    long res=0;
    int length=0;
    for (int i=1;i<=n;i++){
        if ((i&(i-1))==0){
            length++;
        }
        res=((res<<length)|i)%1000000007;
    }
    return res;
}