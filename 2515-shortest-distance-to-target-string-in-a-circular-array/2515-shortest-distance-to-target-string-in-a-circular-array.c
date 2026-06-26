int closestTarget(char** words, int wordsSize, char* target, int startIndex) {
    int min_dist=wordsSize;
    int found=0;
    for(int i=0;i<wordsSize;i++){
        if(strcmp(words[i],target)==0){
            found=1;
            int d=abs(i-startIndex);
            int circ_d=wordsSize-d;
            int actual_d=d<circ_d?d:circ_d;
            if(actual_d<min_dist)min_dist=actual_d;
        }
    }
    return found?min_dist:-1;
}