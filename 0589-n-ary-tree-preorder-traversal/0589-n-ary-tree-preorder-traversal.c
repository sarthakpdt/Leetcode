/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct Node *root,int *res,int *returnSize){
    if(root==NULL){
        return;
    }
    res[(*returnSize)++]=root->val;
    for (int i=0;i<root->numChildren;i++){
        traverse(root->children[i],res,returnSize);
    }
}
int* preorder(struct Node* root, int* returnSize) {
    *returnSize=0;
    int *stack=(int *)malloc(10000*sizeof(int));
    traverse(root,stack,returnSize);
    return stack;
}