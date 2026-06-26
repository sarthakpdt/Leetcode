/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head||!head->next||k==0){ 
        return head;
    }
    struct ListNode *curr=head;
    int n=1;
    while(curr->next!=NULL){
        curr=curr->next;
        n++;
    }
    curr->next=head;
    struct ListNode *tail=head;
    for (int i=0;i<(n-(k%n)-1);i++){
        tail=tail->next;
    }
    struct ListNode *newhead=tail->next;
    tail->next=NULL;
    return newhead;
}