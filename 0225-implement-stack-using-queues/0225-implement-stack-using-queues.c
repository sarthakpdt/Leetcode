#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

Queue* queueCreate() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

void queuePush(Queue* q, int x) {
    if (q->rear == MAX-1) return;
    if (q->front == -1) q->front = 0;
    q->data[++(q->rear)] = x;
}

int queuePop(Queue* q) {
    if (q->front == -1) return -1; // error
    int val = q->data[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return val;
}

int queuePeek(Queue* q) {
    if (q->front == -1) return -1;
    return q->data[q->front];
}

int queueSize(Queue* q) {
    if (q->front == -1) return 0;
    return q->rear - q->front + 1;
}

int queueEmpty(Queue* q) {
    return q->front == -1;
}

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q1 = queueCreate();
    obj->q2 = queueCreate();
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    queuePush(obj->q2, x);
    while (!queueEmpty(obj->q1)) {
        queuePush(obj->q2, queuePop(obj->q1));
    }
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    if (queueEmpty(obj->q1)) return -1;
    return queuePop(obj->q1);
}

int myStackTop(MyStack* obj) {
    if (queueEmpty(obj->q1)) return -1;
    return queuePeek(obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return queueEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}
