/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head==NULL){
        return 0;
    }
    struct ListNode *ptr=head;
    struct ListNode *p=head->next;
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    while (p!=NULL){
        if (p->val==val){
            ptr->next=p->next;
            p=ptr->next;
        }
        else{
            ptr=ptr->next;
            p=p->next;
        }
    }
    return head;
}