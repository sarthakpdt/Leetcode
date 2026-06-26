int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int dis=0;
    int i=0;
    int j=0;

    while (i<nums1Size && j<nums2Size) {
        if (nums1[i]<=nums2[j]) {
            if (j-i>dis) {
                dis=j-i;
            }
            j++;
        } else {
            i++;
        }
    }

    return dis;
}