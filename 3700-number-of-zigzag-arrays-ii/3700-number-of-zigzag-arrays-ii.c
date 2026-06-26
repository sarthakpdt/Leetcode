#define MOD 1000000007LL

typedef long long ll;

ll** matrix_alloc(int n, int m) {
    ll** mat = (ll**)malloc(n * sizeof(ll*));
    for (int i = 0; i < n; i++) {
        mat[i] = (ll*)calloc(m, sizeof(ll));
    }
    return mat;
}

void matrix_free(ll** mat, int n) {
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

ll** mul(ll** a, ll** b, int an, int am, int bm) {
    ll** res = matrix_alloc(an, bm);

    for (int i = 0; i < an; i++) {
        for (int k = 0; k < am; k++) {
            ll r = a[i][k];
            if (r == 0) {
                continue;
            }
            for (int j = 0; j < bm; j++) {
                res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

void pow_mul(ll** base, int size, ll exp, ll** res) {
    ll** base_copy = matrix_alloc(size, size);
    ll** res_copy = matrix_alloc(1, size);

    for (int i = 0; i < size; i++) {
        memcpy(base_copy[i], base[i], size * sizeof(ll));
    }
    memcpy(res_copy[0], res[0], size * sizeof(ll));

    while (exp > 0) {
        if (exp & 1) {
            ll** temp = mul(res_copy, base_copy, 1, size, size);
            matrix_free(res_copy, 1);
            res_copy = temp;
        }
        ll** temp = mul(base_copy, base_copy, size, size, size);
        matrix_free(base_copy, size);
        base_copy = temp;
        exp >>= 1;
    }

    memcpy(res[0], res_copy[0], size * sizeof(ll));

    matrix_free(base_copy, size);
    matrix_free(res_copy, 1);
}

int zigZagArrays(int n, int l, int r) {
    int m = r - l + 1;
    if (n == 1) {
        return m;
    }

    int size = 2 * m;
    ll** u = matrix_alloc(size, size);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            u[i][j + m] = 1;
        }
        for (int j = i + 1; j < m; j++) {
            u[i + m][j] = 1;
        }
    }

    ll** dp = matrix_alloc(1, size);
    for (int i = 0; i < size; i++) {
        dp[0][i] = 1;
    }

    pow_mul(u, size, (ll)(n - 1), dp);
    ll ans = 0;
    for (int i = 0; i < size; i++) {
        ans = (ans + dp[0][i]) % MOD;
    }

    matrix_free(u, size);
    matrix_free(dp, 1);

    return (int)ans;
}