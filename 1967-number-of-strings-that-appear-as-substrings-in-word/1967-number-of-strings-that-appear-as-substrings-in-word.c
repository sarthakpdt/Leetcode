int numOfStrings(char** patterns, int patternsSize, char* word) {
    int n=strlen(word);
    int total=(n*(n+1))/2;
    char substring[total][n+1];
    int count1=0;
    for (int i=0;i<n;i++){
        for (int j=1;j<=n-i;j++){
            strncpy(substring[count1],&word[i],j);
            substring[count1][j]='\0';
            count1++;
        }
    }
    int count=0;
    for (int i=0;i<patternsSize;i++){
        for (int j=0;j<total;j++){
            if (strcmp(patterns[i],substring[j])==0){
                count++;
                break;
            }
        }
    }
    return count;
}