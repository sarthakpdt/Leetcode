int smallestNumber(int n, int t) {
    while(1){
        int b=1;
        int a=n;
        while(a>0){
            b*=a%10;
            a/=10;
        }
        if (b%t==0){
            return n;
        }
        n++;
    }
}