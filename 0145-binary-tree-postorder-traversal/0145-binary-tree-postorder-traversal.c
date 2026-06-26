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
void postorderHelper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    postorderHelper(root->left, arr, index);
    postorderHelper(root->right, arr, index);
    arr[(*index)++] = root->val;
}

// Main function
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    postorderHelper(root, arr, &index);
    return arr;
}