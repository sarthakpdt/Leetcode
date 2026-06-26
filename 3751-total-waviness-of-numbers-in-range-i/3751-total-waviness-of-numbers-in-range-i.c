int totalWaviness(int num1, int num2) {
    int count1=0;
    int peak=0;
    int valley=0;
    int temp1=num1;
    while(temp1!=0){
        count1++;
        temp1=temp1/10;
    }
    int temp2=num2;
    int count2=0;
    while(temp2!=0){
        count2++;
        temp2=temp2/10;
    }
    char string1[count2+1];
    for (int i=num1;i<=num2;i++){
        snprintf(string1,count2+1,"%d",i);
        int num1len=strlen(string1);
        if(num1len<3){
            continue;
        }
        for (int j=1;j<num1len-1;j++){
            if (string1[j]>string1[j+1] && string1[j]>string1[j-1]){
                peak++;
            }
            else if (string1[j]<string1[j+1] && string1[j]<string1[j-1]){
                valley++;
            }
        }
    }
    int waviness=peak+valley;
    return waviness;
}