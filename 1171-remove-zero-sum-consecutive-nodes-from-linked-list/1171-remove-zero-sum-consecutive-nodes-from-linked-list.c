/**
 * Definition for a singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val=0;
    dummy.next=head;
    int changed=1;
    while(changed){
        changed=0;
        struct ListNode *prev=&dummy;
        while(prev!=NULL){
            int sum=0;
            struct ListNode *curr=prev->next;
            while(curr!=NULL){
                sum+=curr->val;
                if(sum==0){
                    prev->next=curr->next;
                    changed=1;
                    break;
                }
                curr=curr->next;
            }
            if(changed){
                break;
            }
            prev=prev->next;
        }
    }
    return dummy.next;
}