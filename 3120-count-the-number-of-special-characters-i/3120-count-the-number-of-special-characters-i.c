int numberOfSpecialChars(char* word) {
    int count=0;
    bool countt[26]={false};
    for (int i=0;word[i]!='\0';i++){
        if (islower(word[i])&& !countt[word[i]-'a']){
            char tar=toupper(word[i]);
            for (int j=0;word[j]!='\0';j++){
                if (word[j]==tar){
                    count++;
                    countt[word[i]-'a']=true;
                    break;
                }
            }
        }
    }
    return count;
}