bool hasAllCodes(char* s, int k){
    int n=strlen(s);
    int total=1<<k;
    if(n<k)return false;
    bool* found=(bool*)calloc(total, sizeof(bool));
    int count=0;
    for(int i=0; i<=n-k; i++){
        int num=0;
        for(int j=0; j<k; j++){
            num=(num<<1)|(s[i+j]-'0');
        }
        if(!found[num]){
            found[num]=true;
            count++;
        }
    }
    free(found);
    return count==total;
}
