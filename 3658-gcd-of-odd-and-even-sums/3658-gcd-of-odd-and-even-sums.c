int gcdOfOddEvenSums(int n) {
    int evenarray[1000];
    int oddarray[1000];
    int sumeven=0;
    int sumodd=0;
    int e=0;
    int o=0;
    int i=1;
    while(e<1000 || o<1000){
        if (i%2==0){
            evenarray[e]=i;
            e++;
        }
        else{
            oddarray[o]=i;
            o++;
        }
        i++;
    }
    for(int i=0;i<n;i++){
        sumeven+=evenarray[i];
        sumodd+=oddarray[i];
    }
    while(sumeven!=0){
        int temp=sumeven;
        sumeven=sumodd%temp;
        sumodd=temp;
    }
    return sumodd;
}