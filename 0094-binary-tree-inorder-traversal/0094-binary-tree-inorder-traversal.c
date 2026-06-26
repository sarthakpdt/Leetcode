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

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node is already provided by the problem.
 * DO NOT redefine it.
 */

/**
 * Helper function to perform inorder traversal and store values in an array.
 */
void inorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root==NULL) return;
    inorderHelper(root->left, result, index);  
    result[(*index)++]=root->val;  
    inorderHelper(root->right, result, index); 
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result=(int*)malloc(100*sizeof(int));
    *returnSize=0;
    inorderHelper(root, result, returnSize);
    return result;  
}
