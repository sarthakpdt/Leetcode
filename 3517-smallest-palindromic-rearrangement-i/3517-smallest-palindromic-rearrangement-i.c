char* smallestPalindrome(char* s) {
    int freq[26]={0};
    int len=strlen(s);
    for(int i=0;i<len;i++){
        freq[s[i]-'a']++;
    }
    char *ans=(char *)malloc((len+1)*sizeof(char));
    int k=0;
    for(int i=0;i<26;i++){
        int count=freq[i]/2;
        while(count--){
            ans[k++]=i+'a';
        }
    }
    for(int i=0;i<26;i++){
        if(freq[i]%2==1){
            ans[k++]=i+'a';
            break;
        }
    }
    for(int i=25;i>=0;i--){
        int count=freq[i]/2;
        while(count--){
            ans[k++]=i+'a';
        }
    }
    ans[k]='\0';
    return ans;
}