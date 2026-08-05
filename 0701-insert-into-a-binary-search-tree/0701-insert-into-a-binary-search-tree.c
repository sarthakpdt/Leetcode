/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root==NULL){
        struct TreeNode *node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val=val;
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    if (val>root->val){
        root->right=insertIntoBST(root->right,val);
    }
    else{
        root->left=insertIntoBST(root->left,val);
    }
    return root;
}