class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        int R = dp.size(), C = dp[0].size();
        dp[R - 1][C - 1] = true;
        for (int r = R - 1; r >= 0; --r) {
            dp[r][C - 1] = s1[r] == s3[r + C - 1];
        }
        for (int c = C - 1; c >= 0; --c) {
            dp[R - 1][c] = s2[c] == s3[c + R - 1];
        }
        for (int r = R - 1; r >= 0; --r) {
            for (int c = C - 1; c >= 0; --c) {
                if (s1[r] == s3[r + c]) {
                    dp[r][c] = dp[r][c] || dp[r + 1][c];
                }
                if (s2[c] == s3[r + c]) {
                    dp[r][c] = dp[r][c] || dp[r][c + 1];
                }
            }
        }
        return dp[0][0];
    }
};
