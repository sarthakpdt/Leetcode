struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    // 1. Create a dummy node to anchor the beginning of our modified list
    struct ListNode dummy;
    dummy.next = head;
    
    // 'beforeGroup' tracks the node right before the section we want to reverse
    struct ListNode* beforeGroup = &dummy;

    while (true) {
        // 2. Check if there are at least 'k' nodes available ahead
        struct ListNode* checker = beforeGroup;
        for (int i = 0; i < k; i++) {
            checker = checker->next;
            // If we hit NULL before reaching k nodes, we are completely done!
            if (checker == NULL) {
                return dummy.next;
            }
        }

        // 3. We have 'k' nodes. Let's set up pointers to reverse this group
        struct ListNode* prev = beforeGroup->next; // Will become the tail of the group
        struct ListNode* curr = prev->next;        // The node we are currently moving
        
        // 4. Perform the reversal loop k - 1 times
        for (int i = 1; i < k; i++) {
            struct ListNode* nextNode = curr->next; // Save the rest of the list
            
            // Perform the pointer dance to push 'curr' to the front of the group
            curr->next = beforeGroup->next;
            beforeGroup->next = curr;
            prev->next = nextNode;
            
            // Move to the next node to process
            curr = nextNode;
        }

        // 5. Move 'beforeGroup' forward to point to the tail of our newly reversed group
        beforeGroup = prev;
    }
}