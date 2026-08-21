/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode *ptr=head;
    struct ListNode *curr=head;
    int count=0;
    struct ListNode *prev=head;
    while (prev!=NULL){
        count++;
        prev=prev->next;
    }
    for(int i=1;i<k;i++){
        ptr=ptr->next;
    }
    for (int i=1;i<(count-k+1);i++){
        curr=curr->next;
    }
    swap(&ptr->val,&curr->val);
    return head;
}