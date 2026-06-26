/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    int count=0;
    struct ListNode *curr=head;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    int* arr=(int*)malloc(count*sizeof(int));
    curr=head;
    for(int i=0;i<count;i++){
        arr[i]=curr->val;
        curr=curr->next;
    }
    int max=0;
    struct ListNode *curr2=head;
    for (int i=0;i<count/2;i++){
        int sum=arr[i]+arr[count-i-1];
        if (sum>max){
            max=sum;
        }
    }
    return max;
}