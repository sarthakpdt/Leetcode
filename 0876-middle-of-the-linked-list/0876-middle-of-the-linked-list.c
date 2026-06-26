/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int countnode(struct ListNode *head){
    int count=0;
    struct ListNode *p=head;
    while (p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
struct ListNode* middleNode(struct ListNode* head) {
    int count=countnode(head);
    int mid=count/2;
    struct ListNode *ptr=head;
    for (int i=0;i<mid;i++){
        ptr=ptr->next;
    }
    return ptr;
}