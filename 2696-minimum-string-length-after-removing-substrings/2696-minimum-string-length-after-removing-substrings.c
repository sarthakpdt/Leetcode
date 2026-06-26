int minLength(char* s) {
    int top=-1;
    int len=strlen(s);
    char *stack=(char *)malloc((len+1)*sizeof(char));
    int i=0;
    while(s[i]!='\0'){
        stack[++top]=s[i];
        if (top>=1){
            if (stack[top]=='B' && stack[top-1]=='A'){
                char res1=stack[top--];
                char res2=stack[top--];
            }
            else if (stack[top]=='D' && stack[top-1]=='C'){
                char res1=stack[top--];
                char res2=stack[top--];
            }
        }
        i++;
    }
    return top+1;
}