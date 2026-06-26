char* mapWordWeights(char** words, int wordsSize, int* weights, int weightsSize) {
    char *string=(char *)malloc((wordsSize+1)*sizeof(char));
    for (int i=0;i<wordsSize;i++){
        int j=0;
        int total=0;
        while(words[i][j]!='\0'){
            int no=words[i][j]-'a';
            total+=weights[no];
            j++;
        }
        int res=total%26;
        string[i]='z'-res;
    }
    string[wordsSize]='\0';
    return string;
}