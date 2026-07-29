/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head) {
    if (head->val>=5){
        struct ListNode *node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val=0;
        node->next=head;
        head=node;
    }
    struct ListNode *curr=head;
    while(curr!=NULL){
        curr->val=(curr->val*2)%10;
        if (curr->next!=NULL && curr->next->val>=5){
            curr->val++;
        }
        curr=curr->next;
    }
    return head;
}