/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int arr[10000];
int j=0;
void in(struct TreeNode *root){
    if (root==NULL){
        return;
    }
    in(root->left);
    arr[j++]=root->val;
    in(root->right);
}
int getMinimumDifference(struct TreeNode* root) {
    j=0;
    in(root);
    int min=INT_MAX;
    for(int i=1;i<j;i++){
        int diff=arr[i]-arr[i-1];
        if(diff<min){
            min=diff;
        }
    }
    return min;
}