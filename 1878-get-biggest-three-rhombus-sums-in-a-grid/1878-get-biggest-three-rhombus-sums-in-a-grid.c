int*getBiggestThree(int**grid,int gridSize,int*gridColSize,int*returnSize){
    int m=gridSize,n=gridColSize[0];
    int sums[3]={0,0,0};
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;i+2*k<m&&j-k>=0&&j+k<n;k++){
                int s;
                if(k==0){
                    s=grid[i][j];
                }else{
                    s=grid[i][j]+grid[i+2*k][j]+grid[i+k][j-k]+grid[i+k][j+k];
                    for(int x=1;x<k;x++){
                        s+=grid[i+x][j-x]+grid[i+x][j+x]+grid[i+2*k-x][j-x]+grid[i+2*k-x][j+x];
                    }
                }
                int exists=0;
                for(int l=0;l<count;l++)if(sums[l]==s)exists=1;
                if(!exists){
                    if(count<3){
                        sums[count++]=s;
                    }else if(s>sums[2]){
                        sums[2]=s;
                    }
                    for(int a=0;a<count;a++){
                        for(int b=a+1;b<count;b++){
                            if(sums[a]<sums[b]){
                                int t=sums[a];
                                sums[a]=sums[b];
                                sums[b]=t;
                            }
                        }
                    }
                }
            }
        }
    }
    int*res=(int*)malloc(count*sizeof(int));
    for(int i=0;i<count;i++)res[i]=sums[i];
    *returnSize=count;
    return res;
}
