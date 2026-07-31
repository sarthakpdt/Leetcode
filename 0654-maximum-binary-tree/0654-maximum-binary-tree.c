/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (numsSize==0){
        return 0;
    }
    int max=nums[0];
    int index=0;
    for (int i=1;i<numsSize;i++){
        int a=nums[i];
        if (max<a){
            max=a;
            index=i;
        }
    }
    root->val=max;
    int lcount=index;
    int rcount=numsSize-index-1;
    int *larray=(int *)malloc(sizeof(int)*lcount);
    int *rarray=(int *)malloc(sizeof(int)*rcount);
    for (int i=0;i<lcount;i++){
        larray[i]=nums[i];
    }
    for (int j=0;j<rcount;j++){
        rarray[j]=nums[index+1+j];
    }
    root->left=constructMaximumBinaryTree(larray,lcount);
    root->right=constructMaximumBinaryTree(rarray,rcount);
    return root;
}