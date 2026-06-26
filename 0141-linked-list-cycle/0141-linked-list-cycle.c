/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p=head;
    struct ListNode *ptr=head;
    while (ptr!=NULL && ptr->next!=NULL){
        p=p->next;
        ptr=ptr->next->next;
        if (p==ptr){
        return true;
        }
    }
    return false;
}