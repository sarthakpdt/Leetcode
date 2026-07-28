/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode low;
    struct ListNode high;
    low.next=NULL;
    high.next=NULL;
    struct ListNode *lcurr=&low;
    struct ListNode *hcurr=&high;
    struct ListNode *curr=head;
    while(curr!=NULL){
        if (curr->val<x){
            lcurr->next=curr;
            lcurr=lcurr->next;
        }
        else{
            hcurr->next=curr;
            hcurr=hcurr->next;
        }
        curr=curr->next;
    }
    hcurr->next=NULL;
    lcurr->next=high.next;
    return low.next;
}