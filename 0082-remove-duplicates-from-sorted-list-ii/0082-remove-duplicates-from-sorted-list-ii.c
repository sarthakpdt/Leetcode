/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head==NULL){
        return 0;
    }
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode *curr=head;
    struct ListNode *prev=&dummy;
    while (curr!=NULL){
        if(curr->next!=NULL && curr->val==curr->next->val){
            while(curr->next!=NULL && curr->val==curr->next->val){
                curr=curr->next;
            }
            prev->next=curr->next;
        }
        else{
            prev=prev->next;
        }
        curr=curr->next;
    }
    return dummy.next;
}