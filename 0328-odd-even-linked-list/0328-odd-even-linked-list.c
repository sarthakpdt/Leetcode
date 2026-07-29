/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode *ocurr=head;
    struct ListNode *ecurr=head->next;
    struct ListNode *join=ecurr;
    while(ecurr!=NULL && ecurr->next!=NULL){
        ocurr->next=ecurr->next;
        ocurr=ocurr->next;
        ecurr->next=ocurr->next;
        ecurr=ecurr->next;
    }
    ocurr->next=join;
    return head;
}