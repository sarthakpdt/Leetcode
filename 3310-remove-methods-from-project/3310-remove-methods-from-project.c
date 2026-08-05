/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct EdgeNode {
    int vertex;
    struct EdgeNode* next;
} EdgeNode;
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void push(Queue* q, int value) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int pop(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    QueueNode* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}
bool isEmpty(Queue* q) { return q->front == NULL; }
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        pop(q);
    }
    free(q);
}
void addEdge(EdgeNode** edges, int u, int v) {
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->vertex = v;
    newNode->next = edges[u];
    edges[u] = newNode;
}
void freeEdges(EdgeNode** edges, int n) {
    for (int i = 0; i < n; i++) {
        EdgeNode* curr = edges[i];
        while (curr != NULL) {
            EdgeNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(edges);
}
int* remainingMethods(int n, int k, int** invocations, int invocationsSize,
                      int* invocationsColSize, int* returnSize) {
    EdgeNode** edges = (EdgeNode**)calloc(n, sizeof(EdgeNode*));
    int* inDegree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        addEdge(edges, u, v);
        inDegree[v]++;
    }
    Queue* queue = createQueue();
    push(queue, k);
    unsigned char* suspicious =
        (unsigned char*)calloc(n, sizeof(unsigned char));
    suspicious[k] = 1;
    while (!isEmpty(queue)) {
        int u = pop(queue);
        EdgeNode* curr = edges[u];
        while (curr != NULL) {
            int v = curr->vertex;
            inDegree[v]--;
            if (suspicious[v] == 0) {
                push(queue, v);
                suspicious[v] = 1;
            }
            curr = curr->next;
        }
    }
    freeQueue(queue);
    bool canRemoveAll = true;
    int* remaining = (int*)malloc(sizeof(int) * n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (suspicious[i] == 1 && inDegree[i] > 0) {
            canRemoveAll = false;
            break;
        } else if (suspicious[i] == 0) {
            remaining[count++] = i;
        }
    }
    if (!canRemoveAll) {
        free(remaining);
        remaining = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            remaining[i] = i;
        }
        *returnSize = n;
    } else {
        *returnSize = count;
    }
    freeEdges(edges, n);
    free(inDegree);
    free(suspicious);
    return remaining;
}