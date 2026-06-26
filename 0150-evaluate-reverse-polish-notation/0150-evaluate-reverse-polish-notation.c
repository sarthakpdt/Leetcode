int evalRPN(char** tokens, int tokensSize) {
    int *stack=(int *)malloc(tokensSize*sizeof(int));
    int top=-1;
    for (int i=0;i<tokensSize;i++){
        char *current=tokens[i];
        if (strlen(current)==1 && (current[0]=='+' || current[0]=='-' || current[0]=='*' || current[0]=='/')){ 
            int b=stack[top--];
            int a=stack[top--];    
            if (current[0]=='+'){
                stack[++top]=a+b;
            }
            else if (current[0]=='-'){
                stack[++top]=a-b;
            }
            else if (current[0]=='*'){
                stack[++top]=a*b;
            }
            else if (current[0]=='/'){
                stack[++top]=a/b;
            }
        }
        else {
            stack[++top]=atoi(current); 
        }
    }
    int res=stack[top];
    return res;
}