int maxProfit(int* prices,int pricesSize){
    if(pricesSize==0){
        return 0;
    }
    int min=prices[0];
    int profit=0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]<min){
            min=prices[i];
        }
        else{
            int curr=prices[i]-min;
            if(curr>profit){
                profit=curr;
            }
        }
    }
    return profit;
}