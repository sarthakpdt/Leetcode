/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* curr=head;
    struct ListNode lessDummy, greaterDummy;
    struct ListNode *po=&lessDummy;
    struct ListNode *pi=&greaterDummy;
    while(curr!=NULL){
        if (curr->val<x){
            po->next=curr;
            po=po->next;
        }
        else{
            pi->next=curr;
            pi=pi->next;
        }
        curr=curr->next;
    }
    pi->next=NULL;
    po->next=greaterDummy.next;
    return lessDummy.next;
}