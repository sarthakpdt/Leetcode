char* findDifferentBinaryString(char** nums, int numsSize) {
    int rows=1<<numsSize;
    char *res=(char *)malloc((numsSize+1)*sizeof(char));
    for (int i=0;i<rows;i++){
        char curr[numsSize+1];
        for (int j=0;j<numsSize;j++){
            curr[j]=((i>>(numsSize-1-j))&1)?'1':'0';
        }
        curr[numsSize]='\0';
        int remele=0;;
        for (int i=0;i<numsSize;i++){
            if (strcmp(curr,nums[i])==0){
                remele=1;
                break;
            }
        }
        if (remele==0){
            strcpy(res,curr);
            return res;
        }
    }
    return "";
}