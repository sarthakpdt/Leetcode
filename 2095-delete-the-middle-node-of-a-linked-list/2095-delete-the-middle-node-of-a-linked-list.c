/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head==NULL || head->next==NULL){
        return NULL;
    }
    struct ListNode *curr=head;
    int count=0;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    if (count%2!=0){
        struct ListNode *curr1=head->next;
        struct ListNode *prev1=head;
        int i=1;
        while (i<count/2){
            curr1=curr1->next;
            prev1=prev1->next;
            i++;
        }
        prev1->next=curr1->next;
    }
    else{
        struct ListNode *curr2=head->next;
        struct ListNode *prev2=head;
        int j=1;
        while (j<count/2){
            curr2=curr2->next;
            prev2=prev2->next;
            j++;
        }
        prev2->next=curr2->next;
    }
    return head;
}