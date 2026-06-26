
char* decodeCiphertext(char* encodedText, int rows) {
    if (rows==1) return encodedText;
    const int N=strlen(encodedText), cols=N/rows;
    char* dec=(char*)malloc(N+1);//Use only malloc
    int sz=0;
    for (int start=0; start<cols; start++) {
        for (int r=0, c=start; r<rows && c<cols; r++, c++) {
            dec[sz++]=encodedText[r*cols+c];  
        }
    }
    while (sz>0 && dec[sz-1]==' ') sz--;
    dec[sz]='\0';
    return dec;
}