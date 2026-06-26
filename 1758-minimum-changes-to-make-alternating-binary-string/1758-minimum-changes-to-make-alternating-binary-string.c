int minOperations(char* s) {
    int count0=0;
    int count1=0;
    for (int i=0;s[i]!='\0';i++){
        if (i%2==0){
            if (s[i]!='0'){
                count0++;
            }
            if (s[i]!='1'){
                count1++;
            }
        }
        else{
            if (s[i]!='0'){
                count1++;
            }
            if (s[i]!='1'){
                count0++;
            }
        }
    }
    return (count0<count1)?count0:count1;
}