bool isValid(char* s) {
    int len=strlen(s);
    char *stack=(char *)malloc(len*sizeof(char));
    int top=-1;
    for (int i=0;i<len;i++){
        char current=s[i];
        if (current=='(' || current=='{' || current=='['){
            stack[++top]=current;
        }
        else{
            if (top==-1){
                return 0;
            }
            char topp=stack[top];
            if ((current==')' && topp=='(') || (current=='}' && topp=='{') || (current==']' && topp=='[')){
                top--;
            }
            else{
                return 0;
            }
        }
    } 
    if (top==-1){
        return 1;
    }
    return 0;
}