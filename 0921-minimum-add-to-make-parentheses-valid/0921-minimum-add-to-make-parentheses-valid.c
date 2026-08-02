int minAddToMakeValid(char* s) {
    int n=strlen(s);
    char *stack=(char *)malloc(n*sizeof(char));
    int i=0;
    int top=-1;
    while (s[i]!='\0'){
        if (s[i]=='('){
            stack[++top]=s[i];
        }
        else if (s[i]==')'){
            if (top>=0 && stack[top]=='('){
                top--;
            }
            else{
                stack[++top]=s[i];
            }
        }
        i++;
    }
    return top+1;
}