/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void reverseInOrder(struct TreeNode* root,int* sum){
    if (root==NULL){
        return;
    }   
    //reverseInOrder(root,sum);
    reverseInOrder(root->right,sum);
    *sum+=root->val;
    root->val=*sum;
    reverseInOrder(root->left,sum);
}
struct TreeNode* convertBST(struct TreeNode* root){
    int sum=0;
    reverseInOrder(root,&sum);
    return root;
}