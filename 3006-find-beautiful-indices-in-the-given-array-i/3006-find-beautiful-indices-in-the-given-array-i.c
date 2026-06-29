int* beautifulIndices(char* s,char* a,char* b,int k,int* returnSize){
    int n=strlen(s);
    int la=strlen(a);
    int lb=strlen(b);

    int *posa=(int*)malloc(n*sizeof(int));
    int *posb=(int*)malloc(n*sizeof(int));

    int ca=0,cb=0;

    for(int i=0;i<=n-la;i++){
        if(strncmp(s+i,a,la)==0){
            posa[ca++]=i;
        }
    }

    for(int i=0;i<=n-lb;i++){
        if(strncmp(s+i,b,lb)==0){
            posb[cb++]=i;
        }
    }

    int *ans=(int*)malloc(ca*sizeof(int));
    int cnt=0;
    int j=0;

    for(int i=0;i<ca;i++){

        while(j<cb&&posb[j]<posa[i]-k){
            j++;
        }

        if(j<cb&&abs(posa[i]-posb[j])<=k){
            ans[cnt++]=posa[i];
        }
    }

    *returnSize=cnt;

    free(posa);
    free(posb);

    return ans;
}