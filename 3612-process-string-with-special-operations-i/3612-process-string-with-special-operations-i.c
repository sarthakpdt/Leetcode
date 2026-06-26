char* processStr(char* s) {
    char *stack=(char *)malloc(20000000);
    int top=-1;
    for (int i=0;s[i]!='\0';i++){
        if (s[i]>='a' && s[i]<='z'){
            stack[++top]=s[i];
        }
        else if (s[i]=='*'){
            if (top>=0){
                top-=1;
            }
        }
        else if (s[i]=='#'){
            int len1=top+1;
            for (int j=0;j<len1;j++){
                stack[++top]=stack[j];
            }
        }
        else if (s[i]=='%'){
            int l=0;
            int r=top;
            while(l<r){
                char temp=stack[l];
                stack[l]=stack[r];
                stack[r]=temp;
                r--;
                l++;
            }
        }
    }
    stack[top+1]='\0';
    return stack;
}