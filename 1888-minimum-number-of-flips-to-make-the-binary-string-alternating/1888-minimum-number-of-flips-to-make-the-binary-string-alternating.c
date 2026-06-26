int minFlips(char* s) {
    int len=strlen(s);
    char temp[200002];
    strcpy(temp,s);
    strcat(temp,s);
    int count0=0;
    int count1=0;
    int min=len;
    for (int i=0;i<2*len;i++){
        if (i%2==0){
            if (temp[i]!='0'){
                count0++;
            }
            if (temp[i]!='1'){
                count1++;
            }
        }
        else{
            if (temp[i]!='0'){
                count1++;
            }
            if (temp[i]!='1'){
                count0++;
            }
        }
        if (i>=len){
            int left=i-len;
            if (left%2==0){
                if(temp[left]!='0'){
                    count0--;
                }
                if (temp[left]!='1'){
                    count1--;
                }
            }
            else{
                if (temp[left]!='1'){
                    count0--;
                }
                if (temp[left]!='0'){
                    count1--;
                }
            }
        }
        if (i>=len-1){
            if (count0<min){
                min=count0;
            }
            if (count1<min){
                min=count1;
            }
        }
    }
    return min;
}