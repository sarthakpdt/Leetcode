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
int height(struct TreeNode *root){
    int h1;
    int h2;
    if (root==NULL){
        return 0;
    }
    else{
        h1=1+height(root->left);
        h2=1+height(root->right);
    }
    if(h1>h2){
        return h1;
    }
    else{
        return h2;
    }
}
void sumandcount(struct TreeNode *root,int level,double *sum,int *count){
    if(root==NULL){
        return;
    }
    if (level==0){
        (*sum)+=root->val;
        (*count)++;
    }
    else{
        sumandcount(root->left,level-1,sum,count);
        sumandcount(root->right,level-1,sum,count);
    }
}
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    if (root==NULL){
        *returnSize = 0;
        return NULL;
    }
    int h=height(root);
    double *avg=(double *)malloc(sizeof(double)*h);
    *returnSize=h;
    for (int level = 0; level < h; level++) {
        double sum = 0.0;
        int count = 0;
        sumandcount(root,level,&sum,&count);
        avg[level]=count>0?sum/count:0;
    }
    return avg;
}