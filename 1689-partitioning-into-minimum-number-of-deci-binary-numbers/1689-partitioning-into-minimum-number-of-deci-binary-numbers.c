int minPartitions(char* n) {
    int max=0;
    for (int i=0;n[i]!='\0';i++){
        int cur=n[i]-'0';
        if (cur>max){
            max=cur;
        }
        if (max==9){
            break;
        }
    }
    return max;
}