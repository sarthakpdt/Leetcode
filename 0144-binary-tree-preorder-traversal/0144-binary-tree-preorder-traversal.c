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
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper to fill array in preorder
void preorderHelper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    arr[(*index)++] = root->val;
    preorderHelper(root->left, arr, index);
    preorderHelper(root->right, arr, index);
}

// Main function
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    preorderHelper(root, arr, &index);
    return arr;
}