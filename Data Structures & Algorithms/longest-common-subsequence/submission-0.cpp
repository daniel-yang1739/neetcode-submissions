class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ROW = text1.length(), COL = text2.length();
        vector<vector<int>> dp(ROW + 1, vector<int>(COL + 1, 0));
        for (int r = ROW - 1; r >= 0; --r) {
            for (int c = COL - 1; c >= 0; --c) {
                if (text1[r] == text2[c]) {
                    dp[r][c] = dp[r + 1][c + 1] + 1;
                } else {
                    dp[r][c] = max(dp[r + 1][c], dp[r][c + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
