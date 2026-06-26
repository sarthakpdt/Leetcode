bool rotateString(char* s, char* goal) {
    int len=strlen(s);
    int goalLen=strlen(goal);
    int i=0;
    while (i<len){
        if (strcmp(s,goal)==0){
            return true;
        }
        char temp=s[0];
        for (int j=0;j<len-1;j++){
            s[j]=s[j+1];
        }
        s[len-1]=temp;
        i++;
    }
    return false;
}