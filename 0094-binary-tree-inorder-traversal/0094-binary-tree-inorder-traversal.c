/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root,int *arr,int *index){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr,index);
    arr[(*index)++]=root->val;
    inorder(root->right,arr,index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr=(int *)malloc(sizeof(int)*101);
    *returnSize=0;
    inorder(root,arr,returnSize);
    return arr;
}