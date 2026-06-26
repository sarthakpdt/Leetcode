#define MOD 1000000007

int numberOfStableArrays(int zero, int one, int limit) {
    // dp[i][j][k] -> i zeros, j ones, k is the last bit (0 or 1)
    // We use long long to prevent overflow during addition
    static int dp[201][201][2];
    
    // Reset DP table for each call
    for (int i = 0; i <= zero; i++)
        for (int j = 0; j <= one; j++)
            dp[i][j][0] = dp[i][j][1] = 0;

    // Base cases: sequences of all 0s or all 1s
    for (int i = 1; i <= zero && i <= limit; i++) dp[i][0][0] = 1;
    for (int j = 1; j <= one && j <= limit; j++) dp[0][j][1] = 1;

    for (int i = 1; i <= zero; i++) {
        for (int j = 1; j <= one; j++) {
            // Ending in 0: Can come from any string ending in 1, 
            // plus strings ending in 0 (subtracting those that hit the limit)
            long long val0 = (long long)dp[i - 1][j][0] + dp[i - 1][j][1];
            if (i > limit) val0 -= dp[i - limit - 1][j][1];
            dp[i][j][0] = (val0 + MOD) % MOD;

            // Ending in 1: Can come from any string ending in 0,
            // plus strings ending in 1 (subtracting those that hit the limit)
            long long val1 = (long long)dp[i][j - 1][0] + dp[i][j - 1][1];
            if (j > limit) val1 -= dp[i][j - limit - 1][0];
            dp[i][j][1] = (val1 + MOD) % MOD;
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}
