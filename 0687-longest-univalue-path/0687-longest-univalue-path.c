/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int ans=0;
int dfs(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=dfs(root->left);
    int right=dfs(root->right);
    int leftPath=0;
    int rightPath=0;
    if(root->left!=NULL && root->left->val==root->val){
        leftPath=left+1;
    }
    if(root->right!=NULL && root->right->val==root->val){
        rightPath=right+1;
    }
    if(leftPath+rightPath>ans){
        ans=leftPath+rightPath;
    }
    if(leftPath>rightPath){
        return leftPath;
    }
    return rightPath;
}
int longestUnivaluePath(struct TreeNode* root) {
    ans=0;
    dfs(root);
    return ans;
}