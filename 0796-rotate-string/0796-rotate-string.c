bool rotateString(char* s, char* goal) {
    if(strlen(s)!=strlen(goal)){
        return false;
    }
    int n=strlen(s);
    char *temp=(char *)malloc(sizeof(char)*(2*n+1));
    strcpy(temp,s);
    strcat(temp,s);
    bool ans=(strstr(temp,goal)!=NULL);
    free(temp);
    return ans;
}