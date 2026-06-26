int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    // If leaf node
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // If left child is NULL, we must traverse the right subtree
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    
    // If right child is NULL, we must traverse the left subtree
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    
    // If both children exist, get the minimum depth and add 1 for the current node
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return (left < right ? left : right) + 1;
}
