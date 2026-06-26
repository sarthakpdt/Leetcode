int maxDistance(int* colors, int colorsSize) {
    int max=0;
    int dis;
    for (int i=0;i<colorsSize;i++){
        for (int j=i+1;j<colorsSize;j++){
            if (colors[i]!=colors[j]){
                dis=abs(i-j);
                if (dis>max){
                    max=dis;
                }
            }
        }
    }
    return max;
}