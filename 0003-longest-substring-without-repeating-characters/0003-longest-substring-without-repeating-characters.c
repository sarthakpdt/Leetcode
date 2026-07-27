int lengthOfLongestSubstring(char* s) {
    int len=strlen(s);
    if(len==0){
        return 0;
    }
    char *array=(char *)malloc(sizeof(char)*len);
    int l=0;
    int max=0;
    for(int i=0;s[i]!='\0';i++){
        int pos=-1;
        for(int j=0;j<l;j++){
            if(array[j]==s[i]){
                pos=j;
                break;
            }
        }
        if(pos==-1){
            array[l]=s[i];
            l++;
        }
        else{
            int k=0;
            for(int j=pos+1;j<l;j++){
                array[k]=array[j];
                k++;
            }
            l=k;
            array[l]=s[i];
            l++;
        }
        if(l>max){
            max=l;
        }
    }
    free(array);
    return max;
}