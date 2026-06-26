int bitwiseComplement(int n) {
    int revbinnum[32];
    int i=0;
    if (n==0){
        return 1;
    }
    while(n>0){
        revbinnum[i]=n%2;
        n=n/2;
        i++;
    }
    int bin[32];
    int k=0;
    for (int j=i-1;j>=0;j--){
        bin[k]=revbinnum[j];
        k++;
    }
    for (int j=0;j<k;j++){
        if (bin[j]==1){
            bin[j]=0;
        } 
        else{
            bin[j]=1;
        }
    }
    int dec=0;
    int base=1;
    for (int j=k-1;j>=0;j--){
        dec+=bin[j]*base;
        base=base*2;
    }
    return dec;
}