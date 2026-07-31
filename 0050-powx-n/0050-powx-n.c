double myPow(double x, int n) {
    if (n==0){
        return 1.0;
    }
    long long p=n;
    if (p<0){ 
        x=1.0/x;
        p=-p;
    }
    if (p%2==0){
        double half=myPow(x,p/2);
        return half*half;
    } else {
        return x*myPow(x,p-1);
    }
}