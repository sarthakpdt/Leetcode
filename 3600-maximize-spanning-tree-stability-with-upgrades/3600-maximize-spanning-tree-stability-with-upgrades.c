// DSU Structure for connectivity checks
typedef struct {
    int *parent;
    int components;
} DSU;

DSU* createDSU(int n) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dsu->parent[i] = i;
    dsu->components = n;
    return dsu;
}

int find(DSU* dsu, int i) {
    if (dsu->parent[i] == i) return i;
    return dsu->parent[i] = find(dsu, dsu->parent[i]);
}

bool unite(DSU* dsu, int i, int j) {
    int root_i = find(dsu, i);
    int root_j = find(dsu, j);
    if (root_i != root_j) {
        dsu->parent[root_i] = root_j;
        dsu->components--;
        return true;
    }
    return false;
}

void freeDSU(DSU* dsu) {
    free(dsu->parent);
    free(dsu);
}

// Check function for Binary Search
bool canAchieve(int X, int n, int** edges, int edgesSize, int k) {
    DSU* dsu = createDSU(n);
    int upgradesUsed = 0;
    int edgesInTree = 0;

    // 1. Process Mandatory Edges (must == 1)
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 1) {
            if (edges[i][2] < X || !unite(dsu, edges[i][0], edges[i][1])) {
                freeDSU(dsu);
                return false; // Mandatory edge too weak or forms a cycle
            }
            edgesInTree++;
        }
    }

    // 2. Process Optional Edges that are ALREADY strong enough (cost 0)
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 0 && edges[i][2] >= X) {
            if (unite(dsu, edges[i][0], edges[i][1])) {
                edgesInTree++;
            }
        }
    }

    // 3. Process Optional Edges that need an UPGRADE (cost 1)
    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][3] == 0 && edges[i][2] < X && 2 * edges[i][2] >= X) {
            if (upgradesUsed < k) {
                if (unite(dsu, edges[i][0], edges[i][1])) {
                    edgesInTree++;
                    upgradesUsed++;
                }
            }
        }
    }

    bool result = (dsu->components == 1 && edgesInTree == n - 1);
    freeDSU(dsu);
    return result;
}

int maxStability(int n, int** edges, int edgesSize, int* edgesColSize, int k) {
    int low = 1, high = 200000; 
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAchieve(mid, n, edges, edgesSize, k)) {
            ans = mid;
            low = mid + 1; // Try for a higher stability
        } else {
            high = mid - 1;
        }
    }
    return ans;
}