char* smallestSubsequence(char* s) {
    int len=strlen(s);
    int last[26]={0};
    for (int j=0;j<len;j++){
        last[s[j]-'a']=j;
    }
    char *stack=(char *)malloc((len+1)*sizeof(char));
    bool chosen[26]={false};
    int top1=-1;
    int i=0;
    while(s[i]!='\0'){
        char curr=s[i];
        if (chosen[curr-'a']){
            i++;
            continue;
        }
        while(top1>=0 && stack[top1]>curr && last[stack[top1]-'a']>i){
            chosen[stack[top1]-'a']=false;
            top1--;
        }
        stack[++top1]=curr;
        chosen[curr-'a']=true;
        i++;
    }
    stack[top1+1]='\0';
    return stack;
}    