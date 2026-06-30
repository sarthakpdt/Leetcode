struct ListNode* reverse(struct ListNode *head){
    struct ListNode *prev=NULL;
    struct ListNode *curr=head;

    while(curr){
        struct ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}
struct ListNode* removeNodes(struct ListNode* head){
    head=reverse(head);

    int max=head->val;

    struct ListNode *curr=head;

    while(curr&&curr->next){
        if(curr->next->val<max){
            curr->next=curr->next->next;
        }
        else{
            curr=curr->next;
            max=curr->val;
        }
    }

    return reverse(head);
}