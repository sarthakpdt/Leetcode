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
int* largestValues(struct TreeNode* root, int* returnSize) {
    int *arr=(int *)malloc(sizeof(int)*10001);
    *returnSize=0;
    if (root==NULL){
        return arr;
    }
    struct TreeNode **queue=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*10001);
    int front=0;
    int rare=0;
    queue[rare++]=root;
    while (front<rare){
        int size=rare-front;
        int max=queue[front]->val;
        for (int i=0;i<size;i++){
            struct TreeNode *node=queue[front++];
            if (node->val>max){
                max=node->val;
            }
            if (node->left!=NULL){
                queue[rare++]=node->left;
            }
            if (node->right!=NULL){
                queue[rare++]=node->right;
            }
        }
        arr[*returnSize]=max;
        (*returnSize)++;
    }
    return arr;
}