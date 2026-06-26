bool judgeCircle(char* moves) {
    int i=0;
    int countu=0;
    int countd=0;
    int countr=0;
    int countl=0;
    while(moves[i]!='\0'){
        if (moves[i]=='U'){
            countu+=1;
        }
        if (moves[i]=='D'){
            countd+=1;
        }
        if (moves[i]=='L'){
            countl+=1;
        }
        if (moves[i]=='R'){
            countr+=1;
        }
        i++;
    }
    if ((countu==countd) && (countl==countr)){
        return 1;
    }
    else{
        return 0;
    }
}