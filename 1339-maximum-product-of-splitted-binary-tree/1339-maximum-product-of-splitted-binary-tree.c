/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MOD 1000000007
long long total=0;
long long ans=0;
long long findTotal(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return root->val+findTotal(root->left)+findTotal(root->right);
}
long long dfs(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    long long left=dfs(root->left);
    long long right=dfs(root->right);
    long long sum=root->val+left+right;
    long long product=sum*(total-sum);
    if(product>ans){
        ans=product;
    }
    return sum;
}
int maxProduct(struct TreeNode* root) {
    total=findTotal(root);
    ans=0;
    dfs(root);
    return ans%MOD;
}