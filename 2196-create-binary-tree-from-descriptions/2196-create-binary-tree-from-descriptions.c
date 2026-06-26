/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    struct TreeNode** nodeMap = (struct TreeNode**)calloc(100001, sizeof(struct TreeNode*));
    bool* isChild = (bool*)calloc(100001, sizeof(bool));
    for (int i = 0; i < descriptionsSize; i++) {
        int parentVal = descriptions[i][0];
        int childVal = descriptions[i][1];
        int isLeft = descriptions[i][2];
        if (!nodeMap[parentVal]) {
            struct TreeNode* newParent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newParent->val = parentVal;
            newParent->left = NULL;
            newParent->right = NULL;
            nodeMap[parentVal] = newParent;
        }
        if (!nodeMap[childVal]) {
            struct TreeNode* newChild = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newChild->val = childVal;
            newChild->left = NULL;
            newChild->right = NULL;
            nodeMap[childVal] = newChild;
        }
        if (isLeft == 1) {
            nodeMap[parentVal]->left = nodeMap[childVal];
        } else {
            nodeMap[parentVal]->right = nodeMap[childVal];
        }
        isChild[childVal] = true;
    }
    struct TreeNode* root = NULL;
    for (int i = 0; i < descriptionsSize; i++) {
        int parentVal = descriptions[i][0];
        if (!isChild[parentVal]) {
            root = nodeMap[parentVal];
            break;
        }
    }
    free(nodeMap);
    free(isChild);
    return root;
}