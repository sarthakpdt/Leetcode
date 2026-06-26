/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    int* arr = (int*)malloc((encodedSize + 1) * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }
    arr[0] = first;
    for (int i = 0; i < encodedSize; i++) {
        arr[i + 1] = encoded[i] ^ arr[i];
    }
    
    *returnSize = encodedSize + 1;
    return arr;
}
