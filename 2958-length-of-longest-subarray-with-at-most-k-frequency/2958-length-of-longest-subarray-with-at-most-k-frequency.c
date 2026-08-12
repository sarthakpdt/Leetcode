#define SIZE 200003
typedef struct{
    int key;
    int value;
} Hash;
int getIndex(int key){
    if(key<0)
        key=-key;
    return key%SIZE;
}
int maxSubarrayLength(int* nums,int numsSize,int k){
    Hash table[SIZE]={0};
    int left=0;
    int ans=0;
    for(int right=0;right<numsSize;right++){
        int index=getIndex(nums[right]);
        while(table[index].key!=0 && table[index].key!=nums[right]){
            index=(index+1)%SIZE;
        }
        if(table[index].key==0){
            table[index].key=nums[right];
        }
        table[index].value++;
        while(table[index].value>k){
            int leftIndex=getIndex(nums[left]);
            while(table[leftIndex].key!=nums[left]){
                leftIndex=(leftIndex+1)%SIZE;
            }
            table[leftIndex].value--;
            left++;
        }
        int length=right-left+1;
        if(length>ans){
            ans=length;
        }
    }
    return ans;
}