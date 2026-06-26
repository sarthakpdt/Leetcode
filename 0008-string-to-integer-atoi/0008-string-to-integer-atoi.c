int myAtoi(char* s) {
    int i=0;
    int j=0;
    char arr[201]={0};
    while (s[i]==' '){
        i++;
    }
    if (s[i]=='-' || s[i]=='+'){
        arr[j++]=s[i++];
    }
    while (s[i]>='0' && s[i]<='9'){
        if (j<200){ 
            arr[j++]=s[i];
        }
        i++;
    }
    arr[j]='\0';
    long long val=atoll(arr);
    if (val>INT_MAX){ 
        return INT_MAX;
    }
    if (val<INT_MIN){ 
        return INT_MIN;
    }
    return (int)val;
}