struct TreeNode *px=NULL;
struct TreeNode *py=NULL;
int dx=-1;
int dy=-1;
void find(struct TreeNode *root,struct TreeNode *parent,int depth,int x,int y){
    if(root==NULL){
        return;
    }
    if(root->val==x){
        px=parent;
        dx=depth;
    }
    if(root->val==y){
        py=parent;
        dy=depth;
    }
    find(root->left,root,depth+1,x,y);
    find(root->right,root,depth+1,x,y);
}
bool isCousins(struct TreeNode* root,int x,int y){
    find(root,NULL,0,x,y);
    if(dx==dy && px!=py){
        return true;
    }
    return false;
}