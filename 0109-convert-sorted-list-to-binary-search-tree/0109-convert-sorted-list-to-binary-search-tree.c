/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head==NULL){
        return NULL;
    }
    int count=0;
    struct ListNode *curr=head;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    } 
    if (count==1){
        struct TreeNode* leaf=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        leaf->val=head->val;
        leaf->left=NULL;
        leaf->right=NULL;
        return leaf;
    }
    struct ListNode* prev=NULL;
    struct ListNode* point=head;
    struct ListNode* nex=point->next;
    int index=0;
    while(index!=(count/2)){
        prev=point;
        point=point->next;
        if (nex!=NULL){
            nex=nex->next;
        }
        index++;
    }
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=point->val;
    if (prev!=NULL){
        prev->next=NULL;
    }
    root->left=sortedListToBST(head);
    root->right=sortedListToBST(nex);
    return root;
}