/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode *node,int currentvalue) {
    if (node==NULL){
        return 0;
    }
    currentvalue=(currentvalue<<1)|node->val;
    if (node->left == NULL && node->right == NULL) {
        return currentvalue;
    }

    // Recursively sum values from left and right subtrees
    return dfs(node->left, currentvalue) + dfs(node->right, currentvalue);
}

// Main function
int sumRootToLeaf(struct TreeNode* root) {
    return dfs(root, 0);

}
