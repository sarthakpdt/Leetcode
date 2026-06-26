/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    return a > b ? a : b;
}

int helper(struct TreeNode* root, int* diameter) {
    if (root == NULL) {
        return 0;
    }
    int left = helper(root->left, diameter);
    int right = helper(root->right, diameter);
    *diameter = max(*diameter, left + right);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    helper(root, &diameter);
    return diameter;
}