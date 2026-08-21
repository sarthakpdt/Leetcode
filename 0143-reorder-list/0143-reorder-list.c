/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (head==NULL || head->next==NULL){
        return;
    }
    struct ListNode *ptr=head;
    int count=0;
    while (ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    struct ListNode **stack=(struct ListNode **)malloc(sizeof(struct ListNode*)*count);
    int top=-1;
    ptr=head;
    while (ptr!=NULL){
        stack[++top]=ptr;
        ptr=ptr->next;
    }
    struct ListNode *prev=head;
    int step=count/2;
    for (int i=0;i<step;i++){
        struct ListNode *last=stack[top--];
        struct ListNode *next=prev->next;
        prev->next=last;
        last->next=next;
        prev=next;
    }
    prev->next=NULL;
}