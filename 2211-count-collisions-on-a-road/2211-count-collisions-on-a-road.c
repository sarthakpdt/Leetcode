int countCollisions(char* directions) {
    int len=strlen(directions);
    char *stack=(char *)malloc(len*sizeof(char));
    int top=-1;
    int count=0;
    int i=0;
    while(directions[i]!='\0'){
        stack[++top]=directions[i];
        int changed=1;
        while (top>0 && changed){
            changed=0;
            if (stack[top]=='L' && stack[top-1]=='R'){
                top--;
                stack[top]='S';
                count+=2;
                changed=1;
            }
            else if ((stack[top]=='S' && stack[top-1]=='R') || (stack[top]=='L' && stack[top-1]=='S')){
                top--;
                stack[top]='S';
                count+=1;
                changed=1;
            }
        }
        i++;
    }
    return count;
}