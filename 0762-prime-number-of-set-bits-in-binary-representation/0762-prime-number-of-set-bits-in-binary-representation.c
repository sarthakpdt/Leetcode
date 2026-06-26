bool isPrime(int n){
    return (n==2||n==3||n==5||n==7||n==11||n==13||n==17||n==19);
}
int countPrimeSetBits(int left, int right){
    int num=0;
    for (int i=left;i<=right;i++){
        int temp=i;
        int count=0;
        while (temp>0){
            if (temp%2==1){
                count++;
            }
            temp/=2;
        }
        if (isPrime(count)){
            num++;
        }
    }
    return num;
}
