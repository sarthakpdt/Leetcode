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
void dfs(struct TreeNode *root,int path[],int len,char **ans,int *count){
    if(root==NULL){
        return;
    }
    path[len++]=root->val;
    if(root->left==NULL && root->right==NULL){
        char *str=(char *)malloc(1000*sizeof(char));
        str[0]='\0';
        char temp[20];
        for(int i=0;i<len;i++){
            sprintf(temp,"%d",path[i]);
            strcat(str,temp);
            if(i!=len-1){
                strcat(str,"->");
            }
        }
        ans[*count]=str;
        (*count)++;
        return;
    }
    dfs(root->left,path,len,ans,count);
    dfs(root->right,path,len,ans,count);
}
char** binaryTreePaths(struct TreeNode* root,int* returnSize){
    char **ans=(char **)malloc(sizeof(char *)*100);
    int path[100];
    int count=0;
    dfs(root,path,0,ans,&count);
    *returnSize=count;
    return ans;
}