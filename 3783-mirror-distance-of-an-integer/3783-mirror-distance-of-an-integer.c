int mirrorDistance(int n) {
    int a;
    int c=n;
    int b=0;
    while(n>0){
        a=n%10;
        b=b*10+a;
        n=n/10;
    }
    int d=abs(c-b);
    return d;
}