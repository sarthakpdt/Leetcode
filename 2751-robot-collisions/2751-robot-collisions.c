typedef struct{
    int pos;
    int health;
    char dir;
    int idx;
}Robot;

int cmp(const void*a,const void*b){
    Robot*r1=(Robot*)a;
    Robot*r2=(Robot*)b;
    return r1->pos-r2->pos;
}

int*survivedRobotsHealths(int*positions,int n,int*healths,int m,char*directions,int*returnSize){
    Robot*arr=(Robot*)malloc(n*sizeof(Robot));

    for(int i=0;i<n;i++){
        arr[i].pos=positions[i];
        arr[i].health=healths[i];
        arr[i].dir=directions[i];
        arr[i].idx=i;
    }

    qsort(arr,n,sizeof(Robot),cmp);

    int*stack=(int*)malloc(n*sizeof(int));
    int top=-1;

    for(int i=0;i<n;i++){
        if(arr[i].dir=='R'){
            stack[++top]=i;
        }else{
            while(top>=0&&arr[stack[top]].dir=='R'&&arr[i].health>0){
                if(arr[stack[top]].health<arr[i].health){
                    arr[i].health--;
                    arr[stack[top]].health=0;
                    top--;
                }else if(arr[stack[top]].health>arr[i].health){
                    arr[stack[top]].health--;
                    arr[i].health=0;
                }else{
                    arr[stack[top]].health=0;
                    arr[i].health=0;
                    top--;
                    break;
                }
            }
        }
    }

    int*final=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        final[i]=0;
    }

    for(int i=0;i<n;i++){
        if(arr[i].health>0){
            final[arr[i].idx]=arr[i].health;
        }
    }

    int*ans=(int*)malloc(n*sizeof(int));
    int k=0;

    for(int i=0;i<n;i++){
        if(final[i]>0){
            ans[k++]=final[i];
        }
    }

    *returnSize=k;

    free(arr);
    free(stack);
    free(final);

    return ans;
}