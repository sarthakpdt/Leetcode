typedef struct{
    int x,y,dir,w,h;
}Robot;

char* dirs[]={"East","North","West","South"};

Robot* robotCreate(int width,int height){
    Robot* obj=(Robot*)malloc(sizeof(Robot));
    obj->x=0;
    obj->y=0;
    obj->dir=0;
    obj->w=width;
    obj->h=height;
    return obj;
}

void robotStep(Robot* obj,int num){
    int per=2*(obj->w+obj->h)-4;
    num=num%per;
    if(num==0) num=per;

    while(num--){
        int nx=obj->x;
        int ny=obj->y;

        if(obj->dir==0) nx++;
        else if(obj->dir==1) ny++;
        else if(obj->dir==2) nx--;
        else ny--;

        if(nx<0||ny<0||nx>=obj->w||ny>=obj->h){
            obj->dir=(obj->dir+1)%4;
            num++;
        }else{
            obj->x=nx;
            obj->y=ny;
        }
    }
}

int* robotGetPos(Robot* obj,int* retSize){
    int* res=(int*)malloc(2*sizeof(int));
    res[0]=obj->x;
    res[1]=obj->y;
    *retSize=2;
    return res;
}

char* robotGetDir(Robot* obj){
    return dirs[obj->dir];
}

void robotFree(Robot* obj){
    free(obj);
}