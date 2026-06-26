#include <stdio.h>
#include <stdlib.h>

long long dp[1001][1001][2];
int MOD = 1e9 + 7;

int numberOfStableArrays(int zero, int one, int limit) {
    // Reset DP table for each call
    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }

    // Base cases: Arrays consisting only of 0s or only of 1s
    // (Only valid if count <= limit)
    for (int i = 1; i <= fmin(zero, limit); i++) dp[i][0][0] = 1;
    for (int j = 1; j <= fmin(one, limit); j++) dp[0][j][1] = 1;

    for (int i = 1; i <= zero; i++) {
        for (int j = 1; j <= one; j++) {
            // Transitions for ending with 0
            // Current = (Previous 0 + Previous 1) 
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
            if (i > limit) {
                // Subtract arrays that would have had 'limit + 1' consecutive zeros
                dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + MOD) % MOD;
            }

            // Transitions for ending with 1
            dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
            if (j > limit) {
                // Subtract arrays that would have had 'limit + 1' consecutive ones
                dp[i][j][1] = (dp[i][j][1] - dp[i][j - limit - 1][0] + MOD) % MOD;
            }
        }
    }

    return (int)((dp[zero][one][0] + dp[zero][one][1]) % MOD);
}