bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    int x1=rec1[0];
    int y1=rec1[1];
    int x2=rec1[2];
    int y2=rec1[3];

    int x3=rec2[0];
    int y3=rec2[1];
    int x4=rec2[2];
    int y4=rec2[3];

    if (x2<=x3||x4<=x1) {
         return false;
    }
    if (y2<=y3||y4<=y1) {
         return false;
    }

    return true;
}