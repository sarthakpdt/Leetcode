int lengthOfLastWord(char* s) {
    int wrcount=0;
    int spcount=0;
    for (int i=strlen(s)-1;i>=0;i--){
        if (s[i]==' ' && wrcount==0){
            continue;
        }  
        if (s[i]!=' '){
            wrcount++;
        }
        if (wrcount>0 && s[i]==' '){
            break;
        }
    }
    int a=wrcount-spcount;
    return a;
}