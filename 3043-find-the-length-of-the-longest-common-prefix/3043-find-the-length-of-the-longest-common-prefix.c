
// A Trie Node representing a single digit branch (0-9)
typedef struct TrieNode {
    struct TrieNode* children[10];
} TrieNode;

// Helper to create a new empty Trie Node
TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));
    return node;
}

// Inserts a number's digits into the Trie
void insertNumber(TrieNode* root, int num) {
    char str[12];
    int len = sprintf(str, "%d", num);
    
    TrieNode* curr = root;
    for (int i = 0; i < len; i++) {
        int digit = str[i] - '0';
        if (curr->children[digit] == NULL) {
            curr->children[digit] = createTrieNode();
        }
        curr = curr->children[digit];
    }
}

// Finds the length of the longest matching prefix for a given number
int findCommonPrefixLength(TrieNode* root, int num) {
    char str[12];
    int len = sprintf(str, "%d", num);
    
    TrieNode* curr = root;
    int matchCount = 0;
    
    for (int i = 0; i < len; i++) {
        int digit = str[i] - '0';
        if (curr->children[digit] != NULL) {
            matchCount++;
            curr = curr->children[digit];
        } else {
            break; 
        }
    }
    return matchCount;
}

// Recursive helper to clean up Trie memory after execution
void freeTrie(TrieNode* root) {
    if (root == NULL) return;
    for (int i = 0; i < 10; i++) {
        if (root->children[i] != NULL) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    TrieNode* root = createTrieNode();
    int maxLen = 0;

    // 1. Insert all numbers from arr1 into the Prefix Tree
    for (int i = 0; i < arr1Size; i++) {
        insertNumber(root, arr1[i]);
    }

    // 2. Search numbers from arr2 in the Tree to check for matching prefix paths
    for (int j = 0; j < arr2Size; j++) {
        int currentLen = findCommonPrefixLength(root, arr2[j]);
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    // 3. Clean up the tree nodes
    freeTrie(root);
    
    return maxLen;
}