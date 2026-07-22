typedef struct {
    int n;
    int* arr;
    int* seg;
} SegmentTree;

void build(SegmentTree* st, int p, int l, int r) {
    if (l == r) {
        st->seg[p] = st->arr[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(st, p << 1, l, mid);
    build(st, (p << 1) | 1, mid + 1, r);

    st->seg[p] = st->seg[p << 1] > st->seg[(p << 1) | 1]
                     ? st->seg[p << 1]
                     : st->seg[(p << 1) | 1];
}

SegmentTree* createSegmentTree(int* arr, int size) {
    SegmentTree* st = (SegmentTree*)malloc(sizeof(SegmentTree));
    st->arr = arr;
    st->n = size;
    st->seg = (int*)calloc(size * 4, sizeof(int));
    build(st, 1, 0, size - 1);

    return st;
}

int queryInternal(SegmentTree* st, int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        return st->seg[p];
    }

    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) {
        int temp = queryInternal(st, p << 1, l, mid, L, R);
        res = res > temp ? res : temp;
    }
    if (R > mid) {
        int temp = queryInternal(st, (p << 1) | 1, mid + 1, r, L, R);
        res = res > temp ? res : temp;
    }

    return res;
}

int query(SegmentTree* st, int L, int R) {
    if (L > R) {
        return 0;
    }
    return queryInternal(st, 1, 0, st->n - 1, L, R);
}

void freeSegmentTree(SegmentTree* st) {
    free(st->seg);
    free(st);
}

int lowerBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upperBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int* maxActiveSectionsAfterTrade(char* s, int** queries, int queriesSize,
                                 int* queriesColSize, int* returnSize) {
    int n = strlen(s);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnt1++;
    }

    int* zeroBlocks = (int*)malloc(n * sizeof(int));
    int* blockLeft = (int*)malloc(n * sizeof(int));
    int* blockRight = (int*)malloc(n * sizeof(int));
    int m = 0;

    int i = 0;
    while (i < n) {
        int st = i;
        while (i < n && s[i] == s[st]) {
            i++;
        }
        if (s[st] == '0') {
            zeroBlocks[m] = i - st;
            blockLeft[m] = st;
            blockRight[m] = i - 1;
            m++;
        }
    }

    int* ans = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;

    if (m < 2) {  // continuous 0 blocks less than 2 segments, return the answer
                  // directly
        for (int i = 0; i < queriesSize; i++) {
            ans[i] = cnt1;
        }
        free(zeroBlocks);
        free(blockLeft);
        free(blockRight);
        return ans;
    }

    int* tmpSum = (int*)malloc((m - 1) * sizeof(int));
    for (int i = 0; i < m - 1; i++) {
        tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
    }
    SegmentTree* seg = createSegmentTree(tmpSum, m - 1);
    for (int q = 0; q < queriesSize; q++) {
        int l = queries[q][0], r = queries[q][1];
        int leftIdx = lowerBound(blockRight, m, l);
        int rightIdx = upperBound(blockLeft, m, r) - 1;

        // at most 1 continuous block of 0s within the substring
        if (leftIdx > m - 1 || rightIdx < 0 || leftIdx >= rightIdx) {
            ans[q] = cnt1;
            continue;
        }

        int maxLeft = blockLeft[leftIdx] > l ? blockLeft[leftIdx] : l;
        int firstLen = blockRight[leftIdx] - maxLeft +
                       1;  // actual length of the first consecutive block of 0s
                           // in the substring
        int minRight = blockRight[rightIdx] < r ? blockRight[rightIdx] : r;
        int lastLen = minRight - blockLeft[rightIdx] +
                      1;  // actual length of the last consecutive block of 0s
                          // in the substring

        // exactly 2 consecutive 0 blocks within the substring
        if (leftIdx + 1 == rightIdx) {
            int bestGain = firstLen + lastLen;
            ans[q] = cnt1 + bestGain;
            continue;
        }

        int val1 = firstLen + zeroBlocks[leftIdx + 1];
        int val2 = zeroBlocks[rightIdx - 1] + lastLen;
        int val3 = query(seg, leftIdx + 1, rightIdx - 2);
        int bestGain = val1 > val2 ? val1 : val2;
        bestGain = bestGain > val3 ? bestGain : val3;

        ans[q] = cnt1 + bestGain;
    }

    free(zeroBlocks);
    free(blockLeft);
    free(blockRight);
    free(tmpSum);
    freeSegmentTree(seg);

    return ans;
}