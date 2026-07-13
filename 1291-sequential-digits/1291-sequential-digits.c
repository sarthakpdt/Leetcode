/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize) {

    int *array=(int *)malloc(50*sizeof(int));
    int k=0;

    for(int len=2;len<=9;len++){

        for(int start=1;start<=10-len;start++){

            int num=0;

            for(int d=start;d<start+len;d++){
                num=num*10+d;
            }

            if(num>=low && num<=high){
                array[k++]=num;
            }
        }
    }

    *returnSize=k;
    return array;
}