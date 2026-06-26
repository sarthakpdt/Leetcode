int numSteps(char*s){
    int c=0,y=0,n=strlen(s);
    for(int i=n-1;i>0;i--){
        int v=(s[i]-'0')+y;
        if(v==1){
            c+=2;
            y=1;
        }
        else{
            c+=1;
            y=(v==2)?1:0;
        }
    }
    return c+y;
}