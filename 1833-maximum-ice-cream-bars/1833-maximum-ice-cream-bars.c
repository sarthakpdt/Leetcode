int maxIceCream(int* costs,int costsSize,int coins){
    int max=0;

    for(int i=0;i<costsSize;i++){
        if(costs[i]>max){
            max=costs[i];
        }
    }

    int freq[max+1];

    for(int i=0;i<=max;i++){
        freq[i]=0;
    }

    for(int i=0;i<costsSize;i++){
        freq[costs[i]]++;
    }

    int count=0;

    for(int price=1;price<=max;price++){
        while(freq[price]>0&&coins>=price){
            coins-=price;
            count++;
            freq[price]--;
        }
    }

    return count;
}