/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *curr=list1->next;
    struct ListNode *prev=list1;
    struct ListNode *curr2=list2;
    int i=1;
    while(i<a){
        prev=prev->next;
        curr=curr->next;
        i++;
    }
    while(i<b){
        curr=curr->next;
        i++;
    }
    struct ListNode *after=curr->next;
    prev->next=list2;
    while(curr2->next!=NULL){
        curr2=curr2->next;
    }
    curr2->next=after;
    return list1;
}