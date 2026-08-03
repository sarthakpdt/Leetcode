char* addBinary(char* a, char* b) {
    int n1=strlen(a);
    int n2=strlen(b);
    int maxlen=(n1>n2)?n1:n2;
    char *res=(char *)malloc(maxlen+2);
    int i=n1-1;
    int j=n2-1;
    int carry=0;
    int k=0;
    while(i>=0 || j>=0 || carry){
        int sum=carry;
        if(i>=0){
            sum+=a[i]-'0';
            i--;
        }
        if(j>=0){
            sum+=b[j]-'0';
            j--;
        }
        res[k++]=(sum%2)+'0';
        carry=sum/2;
    }
    res[k]='\0';
    // Reverse the string
    int left=0;
    int right=k-1;
    while(left<right){
        char temp=res[left];
        res[left]=res[right];
        res[right]=temp;
        left++;
        right--;
    }
    // Remove leading zeros
    int first=0;
    while(res[first]=='0' && res[first+1]!='\0'){
        first++;
    }
    if(first>0){
        memmove(res,res+first,strlen(res+first)+1);
    }
    return res;
}