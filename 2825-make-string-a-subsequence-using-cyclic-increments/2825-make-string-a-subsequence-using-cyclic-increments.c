bool canMakeSubsequence(char* str1, char* str2) {
    int i=0;
    int j=0;
    while(str1[i]!='\0' && str2[j]!='\0'){
        char next;
        if (str1[i]=='z'){
            next='a';
        }
        else{
            next=str1[i]++;
        }
        if (str1[i]==str2[j] || next==str2[j]){
            j++;
        }
        i++;
    }
    if(str2[j]=='\0'){
        return true;
    }
    return false;
}