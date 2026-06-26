#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void*a,const void*b){
    char*s1=*(char**)a;
    char*s2=*(char**)b;
    return strcmp(s2,s1);
}

char*makeLargestSpecial(char*s){
    int len=strlen(s);
    if(len==0)return s;

    char**chunks=(char**)malloc(len*sizeof(char*));
    int count=0,balance=0,start=0;

    for(int i=0;i<len;i++){
        if(s[i]=='1'){
            balance=balance+1;
        }else{
            balance=balance-1;
        }

        if(balance==0){
            int innerLen=i-start-1;
            char*inner=(char*)malloc(innerLen+1);
            for(int j=0;j<innerLen;j++){
                inner[j]=s[start+1+j];
            }
            inner[innerLen]='\0';

            char*sortedInner=makeLargestSpecial(inner);
            chunks[count]=(char*)malloc(innerLen+3);
            sprintf(chunks[count],"1%s0",sortedInner);

            count=count+1;
            start=i+1;
            free(inner);
        }
    }

    qsort(chunks,count,sizeof(char*),compare);

    char*res=(char*)malloc(len+1);
    res[0]='\0';
    for(int i=0;i<count;i++){
        strcat(res,chunks[i]);
        free(chunks[i]);
    }

    free(chunks);
    strcpy(s,res);
    free(res);
    return s;
}
