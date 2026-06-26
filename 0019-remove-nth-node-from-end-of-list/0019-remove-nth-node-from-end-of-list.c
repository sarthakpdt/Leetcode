/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head){
    if (head==NULL || head->next==NULL){
        return head;
    }
    else{
        struct ListNode *newnode= reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newnode;
    }
}
struct ListNode*removeNthFromStart(struct ListNode*head,int n){
	if(n==1){
		struct ListNode*temp=head;
		head=head->next;
		free(temp);
		return head;
	}
	struct ListNode*curr=head;
	for(int i=1;i<n-1;i++){
		curr=curr->next;
	}
	struct ListNode*temp=curr->next;
	curr->next=temp->next;
	free(temp);
	return head;
}
struct ListNode*removeNthFromEnd(struct ListNode*head,int n){
	head=reverseList(head);
	head=removeNthFromStart(head,n);
	head=reverseList(head);
	return head;
}
