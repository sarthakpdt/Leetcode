bool match(struct ListNode *head,struct TreeNode *root){
    if(head==NULL){
        return true;
    }
    if(root==NULL){
        return false;
    }
    if(head->val!=root->val){
        return false;
    }
    return match(head->next,root->left) || match(head->next,root->right);
}
bool isSubPath(struct ListNode* head,struct TreeNode* root){
    if(root==NULL){
        return false;
    }
    return match(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
}