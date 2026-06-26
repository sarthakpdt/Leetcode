

// Helper pointer to keep track of the current node in the new tree
struct TreeNode* curr;

void inorder(struct TreeNode* node) {
    if (node == NULL) return;

    inorder(node->left);

    // Remove the left link and link current node to right of curr
    node->left = NULL;
    curr->right = node;
    curr = node;

    inorder(node->right);
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode dummy;
    dummy.left = NULL;
    dummy.right = NULL;
    curr = &dummy;

    inorder(root);

    return dummy.right;  // The leftmost node is new root
}