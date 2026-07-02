#define MIN_QUEUE_SIZE 64

typedef struct Element {
    int data[2];
} Element;

typedef bool (*compare)(const void*, const void*);

typedef struct PriorityQueue {
    Element* arr;
    int capacity;
    int queueSize;
    compare lessFunc;
} PriorityQueue;

Element* createElement(int x, int y) {
    Element* obj = (Element*)malloc(sizeof(Element));
    obj->data[0] = x;
    obj->data[1] = y;
    return obj;
}

static bool greater(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    return e1->data[0] > e2->data[0];
}

static void memswap(void* m1, void* m2, size_t size) {
    unsigned char* a = (unsigned char*)m1;
    unsigned char* b = (unsigned char*)m2;
    while (size--) {
        *b ^= *a ^= *b ^= *a;
        a++;
        b++;
    }
}

static void swap(Element* arr, int i, int j) {
    memswap(&arr[i], &arr[j], sizeof(Element));
}

static void down(Element* arr, int size, int i, compare cmpFunc) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        if (k + 1 < size && cmpFunc(&arr[k], &arr[k + 1])) {
            k++;
        }
        if (cmpFunc(&arr[k], &arr[(k - 1) / 2])) {
            break;
        }
        swap(arr, k, (k - 1) / 2);
    }
}

PriorityQueue* createPriorityQueue(compare cmpFunc) {
    PriorityQueue* obj = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    obj->capacity = MIN_QUEUE_SIZE;
    obj->arr = (Element*)malloc(sizeof(Element) * obj->capacity);
    obj->queueSize = 0;
    obj->lessFunc = cmpFunc;
    return obj;
}

void heapify(PriorityQueue* obj) {
    for (int i = obj->queueSize / 2 - 1; i >= 0; i--) {
        down(obj->arr, obj->queueSize, i, obj->lessFunc);
    }
}

void enQueue(PriorityQueue* obj, Element* e) {
    if (obj->queueSize == obj->capacity) {
        obj->capacity *= 2;
        obj->arr = realloc(obj->arr, sizeof(Element) * obj->capacity);
    }
    memcpy(&obj->arr[obj->queueSize], e, sizeof(Element));
    for (int i = obj->queueSize;
         i > 0 && obj->lessFunc(&obj->arr[(i - 1) / 2], &obj->arr[i]);
         i = (i - 1) / 2) {
        swap(obj->arr, i, (i - 1) / 2);
    }
    obj->queueSize++;
}

Element* deQueue(PriorityQueue* obj) {
    swap(obj->arr, 0, obj->queueSize - 1);
    down(obj->arr, obj->queueSize - 1, 0, obj->lessFunc);
    Element* e = &obj->arr[obj->queueSize - 1];
    obj->queueSize--;
    return e;
}

bool isEmpty(const PriorityQueue* obj) { return obj->queueSize == 0; }

Element* front(const PriorityQueue* obj) {
    if (obj->queueSize == 0) {
        return NULL;
    } else {
        return &obj->arr[0];
    }
}

void clear(PriorityQueue* obj) { obj->queueSize = 0; }

int size(const PriorityQueue* obj) { return obj->queueSize; }

void freeQueue(PriorityQueue* obj) {
    free(obj->arr);
    free(obj);
}

bool findSafeWalk(int** grid, int gridSize, int* gridColSize, int health) {
    int m = gridSize, n = gridColSize[0];
    int** dis = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dis[i] = (int*)malloc(n * sizeof(int));
        memset(dis[i], -1, n * sizeof(int));
    }

    int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    PriorityQueue* pq = createPriorityQueue(greater);
    Element* start = createElement(grid[0][0], 0);
    enQueue(pq, start);
    free(start);

    while (!isEmpty(pq)) {
        Element* e = front(pq);
        int val = e->data[0];
        int cx = e->data[1] / n;
        int cy = e->data[1] % n;
        deQueue(pq);
        if (dis[cx][cy] >= 0) {
            continue;
        }
        dis[cx][cy] = val;

        for (int k = 0; k < 4; k++) {
            int nx = cx + dirs[k][0];
            int ny = cy + dirs[k][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || dis[nx][ny] >= 0) {
                continue;
            }

            Element* next = createElement(val + grid[nx][ny], nx * n + ny);
            enQueue(pq, next);
            free(next);
        }
    }

    int result = dis[m - 1][n - 1] < health;
    for (int i = 0; i < m; i++) {
        free(dis[i]);
    }
    free(dis);
    freeQueue(pq);

    return result;
}