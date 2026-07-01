int maximumSafenessFactor(int** grid,int gridSize,int* gridColSize){
    int n=gridSize;

    int **dist=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        dist[i]=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            dist[i][j]=-1;
        }
    }

    typedef struct{
        int x,y;
    }Node;

    Node *q=(Node*)malloc(n*n*sizeof(Node));

    int front=0,rear=0;

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dist[i][j]=0;
                q[rear++]=(Node){i,j};
            }
        }
    }

    while(front<rear){
        Node cur=q[front++];

        for(int k=0;k<4;k++){
            int nx=cur.x+dx[k];
            int ny=cur.y+dy[k];

            if(nx>=0&&nx<n&&ny>=0&&ny<n&&dist[nx][ny]==-1){
                dist[nx][ny]=dist[cur.x][cur.y]+1;
                q[rear++]=(Node){nx,ny};
            }
        }
    }

    int canReach(int limit){
        if(dist[0][0]<limit||dist[n-1][n-1]<limit){
            return 0;
        }

        int **vis=(int**)malloc(n*sizeof(int*));
        for(int i=0;i<n;i++){
            vis[i]=(int*)calloc(n,sizeof(int));
        }

        Node *que=(Node*)malloc(n*n*sizeof(Node));

        int f=0,r=0;

        que[r++]=(Node){0,0};
        vis[0][0]=1;

        while(f<r){
            Node cur=que[f++];

            if(cur.x==n-1&&cur.y==n-1){
                for(int i=0;i<n;i++) free(vis[i]);
                free(vis);
                free(que);
                return 1;
            }

            for(int k=0;k<4;k++){
                int nx=cur.x+dx[k];
                int ny=cur.y+dy[k];

                if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis[nx][ny]&&dist[nx][ny]>=limit){
                    vis[nx][ny]=1;
                    que[r++]=(Node){nx,ny};
                }
            }
        }

        for(int i=0;i<n;i++) free(vis[i]);
        free(vis);
        free(que);

        return 0;
    }

    int low=0;
    int high=2*n;
    int ans=0;

    while(low<=high){
        int mid=(low+high)/2;

        if(canReach(mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    for(int i=0;i<n;i++){
        free(dist[i]);
    }

    free(dist);
    free(q);

    return ans;
}