/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int h1=0;
    int h2=0;
    if (root==NULL){
        return 0;
    }
    else{
        h1=1+maxDepth(root->left);
        h2=1+maxDepth(root->right);
    }
    if (h1>h2){
        return h1;
    }
    else{
        return h2;
    }
}