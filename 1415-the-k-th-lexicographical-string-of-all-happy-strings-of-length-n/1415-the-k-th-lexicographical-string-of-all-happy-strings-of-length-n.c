char *res;
int count;
void dfs(int n,int k,char *temp,int index){
    if (index==n){
        count++;
        if (count==k){
            res=strdup(temp);
        }
        return;
    }
    for (char i='a';i<='c';i++){
        if (index==0 || temp[index-1]!=i){
            temp[index]=i;
            temp[index+1]='\0';
            dfs(n,k,temp,index+1);
            if (res){
                return;
            }
        }
    }
}
char* getHappyString(int n, int k) {
    res=NULL;
    count=0;
    char temp[15]="";
    dfs(n,k,temp,0);
    return res?res:"";
}