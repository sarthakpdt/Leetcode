/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    bool lookup[100001]={false};
    for (int i=0;i<numsSize;i++){
        lookup[nums[i]]=true;
    }
    struct ListNode dummy;
    dummy.next=head;
    struct ListNode *curr=&dummy;
    while(curr->next!=NULL){
        int nxtvalue=curr->next->val;
        if (lookup[nxtvalue]==true){
            curr->next=curr->next->next;
        }
        else{
            curr=curr->next;
        }
    }
    return dummy.next;
}