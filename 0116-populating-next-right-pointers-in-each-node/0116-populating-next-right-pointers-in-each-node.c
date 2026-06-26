/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root==NULL){
        return NULL;
    }
    struct Node *start=root;
    while (start->left!=NULL){
        struct Node *curr=start;
        while (curr!=NULL){
            curr->left->next=curr->right;
            if (curr->next!=NULL){
                curr->right->next=curr->next->left;
            }
            curr=curr->next;
        }
        start=start->left;
    }
    return root;
}