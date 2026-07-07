long long sumAndMultiply(int n) {
    long long b=0;
    long long place=1;
    long long a;
    while(n>0){
        a=n%10;
        if (a!=0){
            b=b*10+a;
        }
        n=n/10;
    }
    long long sum=0;
    long long c;
    long long x=0;
    while(b>0){
        c=b%10;
        x=x*10+c;
        sum+=c;
        b=b/10;
    }
    return sum*x;
}