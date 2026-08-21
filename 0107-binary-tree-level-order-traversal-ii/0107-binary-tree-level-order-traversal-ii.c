/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root==NULL){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }
    int **res=(int **)malloc(sizeof(int*)*2000);
    *returnColumnSizes=(int *)malloc(sizeof(int)*2000);
    struct TreeNode *queue[2000];
    int front=0;
    int rare=0;
    queue[rare++]=root;
    int levelc=0;
    while (front<rare){
        int levels=rare-front;
        (*returnColumnSizes)[levelc]=levels;
        res[levelc]=(int *)malloc(sizeof(int)*levels);
        for (int i=0;i<levels;i++){
            struct TreeNode *node=queue[front++];
            res[levelc][i]=node->val;
            if (node->left){
                queue[rare++]=node->left;
            }
            if (node->right){
                queue[rare++]=node->right;
            }
        }
        levelc++;
    }
    *returnSize=levelc;
    for (int i=0;i<levelc/2;i++){
        int *temp=res[i];
        res[i]=res[levelc-1-i];
        res[levelc-1-i]=temp;
        int temps=(*returnColumnSizes)[i];
        (*returnColumnSizes)[i]=(*returnColumnSizes)[levelc-1-i];
        (*returnColumnSizes)[levelc-1-i]=temps;
    }
    return res;
}