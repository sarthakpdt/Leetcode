void sumleaf(struct TreeNode* root,int sum,int targetSum,bool *flag){
    if (root==NULL){
        return;
    }
    sum+=root->val;
    if (root->left == NULL && root->right == NULL) {
        if (sum==targetSum){
            *flag=true;
        }
        return;
    }
    sumleaf(root->right,sum,targetSum,flag);
    sumleaf(root->left,sum,targetSum,flag);
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root==NULL){
        return false;
    }
    bool flag=false;
    int sum=0;
    sumleaf(root,sum,targetSum,&flag);
    return flag;
}