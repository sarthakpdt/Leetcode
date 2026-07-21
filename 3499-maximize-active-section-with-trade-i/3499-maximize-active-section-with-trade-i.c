int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int maxActiveSectionsAfterTrade(char* s){
    int n=strlen(s);

    char *t=(char *)malloc(n+3);

    t[0]='1';
    for(int i=0;i<n;i++){
        t[i+1]=s[i];
    }
    t[n+1]='1';
    t[n+2]='\0';

    int ones=0;
    for(int i=1;i<=n;i++){
        if(t[i]=='1'){
            ones++;
        }
    }

    int ans=ones;

    int i=1;

    while(i<=n){
        if(t[i]=='1'){

            int j=i;
            while(j<=n&&t[j]=='1'){
                j++;
            }

            if(t[i-1]=='0'&&t[j]=='0'){

                int oneLen=j-i;

                int l=i-1;
                while(l>=0&&t[l]=='0'){
                    l--;
                }

                int leftZero=i-l-1;

                int r=j;
                while(r<=n+1&&t[r]=='0'){
                    r++;
                }

                int rightZero=r-j;

                ans=max(ans,ones+leftZero+rightZero);
            }

            i=j;
        }
        else{
            i++;
        }
    }

    free(t);

    return ans;
}