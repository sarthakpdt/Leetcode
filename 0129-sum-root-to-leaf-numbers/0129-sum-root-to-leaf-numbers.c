/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumNumbersHelper(struct TreeNode* node, int current) {
    if (node == NULL) {
        return 0;
    }
    current = current * 10 + node->val;
    if (node->left == NULL && node->right == NULL) {
        return current;
    }
    return sumNumbersHelper(node->left, current) + sumNumbersHelper(node->right, current);
}

int sumNumbers(struct TreeNode* root) {
    return sumNumbersHelper(root, 0);
}
