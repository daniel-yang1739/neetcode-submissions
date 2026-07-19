class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        int R = dp.size(), C = dp[0].size();
        dp[R - 1][C - 1] = 0;
        for (int r = R - 2; r >= 0; --r) {
            dp[r][C - 1] = dp[r + 1][C - 1] + 1;
        }
        for (int c = C - 2; c >= 0; --c) {
            dp[R - 1][c] = dp[R - 1][c + 1] + 1;
        }
        for (int r = R - 2; r >= 0; --r) {
            for (int c = C - 2; c >= 0; --c) {
                if (word1[r] == word2[c]) {
                    dp[r][c] = dp[r + 1][c + 1];
                } else {
                    dp[r][c] = min({
                        dp[r + 1][c + 1],   // replace
                        dp[r][c + 1],       // insert
                        dp[r + 1][c]        // delete
                    }) + 1;
                }
            }
        }
        return dp[0][0];
    }
};
