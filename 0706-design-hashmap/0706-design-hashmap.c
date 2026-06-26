#include <stdlib.h>

#define BUCKET_SIZE 10007

// Define a linked list node to store key-value pairs
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[BUCKET_SIZE];
} MyHashMap;

// Helper to create a new linked list node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        obj->buckets[i] = NULL;
    }
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int idx = key % BUCKET_SIZE;
    Node* curr = obj->buckets[idx];
    
    // Check if the key already exists, if so, update its value
    while (curr != NULL) {
        if (curr->key == key) {
            curr->value = value;
            return;
        }
        curr = curr->next;
    }
    
    // Key doesn't exist, insert a new node at the head of the chain
    Node* newNode = createNode(key, value);
    newNode->next = obj->buckets[idx];
    obj->buckets[idx] = newNode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int idx = key % BUCKET_SIZE;
    Node* curr = obj->buckets[idx];
    
    // Traverse the chain at this bucket index
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }
    return -1; // Key not found
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int idx = key % BUCKET_SIZE;
    Node* curr = obj->buckets[idx];
    Node* prev = NULL;
    
    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) {
                // Node to remove is the head of the bucket
                obj->buckets[idx] = curr->next;
            } else {
                // Node to remove is in the middle or end
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    // Free all dynamically allocated nodes in every bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* curr = obj->buckets[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj);
}