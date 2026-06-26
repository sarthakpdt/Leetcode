int binaryGap(int n) {
    int bin[32];
    int i=0;
    while (n>0){
        bin[i]=n%2;
        n=n/2;
        i++;
    }  
    int max=0;
    int length=i;
    for (int i=0;i<length;i++){
        if (bin[i]==1){
            for (int j=i+1;j<length;j++){
                if (bin[j]==1){
                    int dis=j-i;
                    if (dis>max){
                        max=dis;
                    }
                    break;
                }
            }
        }
    }
    return max;
}