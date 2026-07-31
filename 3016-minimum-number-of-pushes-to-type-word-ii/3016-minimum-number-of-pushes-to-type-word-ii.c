int cmp(const void *a,const void *b){
    int x=*(int *)a;
    int y=*(int *)b;
    if(x<y){
        return 1;
    }
    if(x>y){
        return -1;
    }
    return 0;
}
int minimumPushes(char* word) {
    int freq[26]={0};
    for (int i=0;word[i]!='\0';i++){
        freq[word[i]-'a']++;
    }
    qsort(freq,26,sizeof(int),cmp);
    int ans=0;
    for (int i=0;i<26;i++){
        if (freq[i]==0){
            break;
        }
        ans+=freq[i]*(i/8+1);
    }
    return ans;
}