#define MOD 1000000007

int zigZagArrays(int n, int l, int r) {
    int* dp0 = (int*)calloc(r + 1, sizeof(int));
    int* dp1 = (int*)calloc(r + 1, sizeof(int));
    int* sum0 = (int*)calloc(r + 2, sizeof(int));
    int* sum1 = (int*)calloc(r + 2, sizeof(int));

    for (int i = l; i <= r; i++) {
        dp0[i] = 1;
        dp1[i] = 1;
        sum0[i] = sum1[i] = i - l + 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = l; j <= r; j++) {
            dp0[j] = (sum1[r] - sum1[j] + MOD) % MOD;
            dp1[j] = sum0[j - 1];
        }

        sum0[l] = dp0[l];
        sum1[l] = dp1[l];
        for (int j = l + 1; j <= r; j++) {
            sum0[j] = (sum0[j - 1] + dp0[j]) % MOD;
            sum1[j] = (sum1[j - 1] + dp1[j]) % MOD;
        }
    }

    int ans = (sum0[r] + sum1[r]) % MOD;

    free(dp0);
    free(dp1);
    free(sum0);
    free(sum1);

    return ans;
}