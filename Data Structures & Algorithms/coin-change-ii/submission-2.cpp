class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        int R = dp.size(), C = dp[0].size();
        for (int r = 0; r < R; ++r) {
            dp[r][0] = 1;
        }
        for (int c = 0; c < C; ++c) {
            if (c >= coins[0] && c % coins[0] == 0) {
                dp[0][c] = 1;
            }
        }
        for (int r = 1; r < R; ++r) {
            for (int c = 1; c < C; ++c) {
                dp[r][c] = dp[r - 1][c];
                int target = c - coins[r];
                if (target >= 0) {
                    dp[r][c] += dp[r][target];
                }
            }
        }
        return dp[R - 1][C - 1];
    }
};
