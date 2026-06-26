int calPoints(char** operations, int operationsSize) {
    int* stack = (int*)malloc(operationsSize * sizeof(int));
    int sum=0;
    int top=-1;
    for (int i=0;i<operationsSize;i++){
        char* op=operations[i];
        if (strcmp(op,"D")==0){
            if (top>=0){
                int val=stack[top]*2;
                stack[++top]=val;
                sum+=val;
            }
        }
        else if (strcmp(op,"+")==0){
            if (top>=1){
                int val=stack[top]+stack[top-1];
                stack[++top]=val;
                sum+=val;
            }
        }
        else if (strcmp(op,"C")==0){
            if (top>=0){
                sum-=stack[top];
                top--;
            }
        }
        else {
            // It's an integer
            int val = atoi(op);
            stack[++top] = val;
            sum += val;
        }
    }
    return sum;
}