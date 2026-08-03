bool isIsomorphic(char* s, char* t) {
    if(strlen(s)!=strlen(t)){
        return false;
    }
    int map1[256]={0};
    int map2[256]={0};
    for(int i=0;s[i]!='\0';i++){
        if(map1[(unsigned char)s[i]]!=map2[(unsigned char)t[i]]){
            return false;
        }
        map1[(unsigned char)s[i]]=i+1;
        map2[(unsigned char)t[i]]=i+1;
    }
    return true;
}