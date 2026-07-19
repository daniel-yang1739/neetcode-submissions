class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int s1Len = s1.length(), s2Len = s2.length();
        if (s1Len + s2Len != s3.length()) return false;
        vector<vector<bool>> dp(s1Len + 1, vector<bool>(s2Len + 1, false));
        int R = dp.size(), C = dp[0].size();
        for (int r = 0; r < R; ++r) {
            dp[r][s2Len] = s1[r] == s3[r + s2Len];
        }
        for (int c = 0; c < C; ++c) {
            dp[s1Len][c] = s2[c] == s3[c + s1Len];
        }
        for (int r = R - 1; r >= 0; --r) {
            for (int c = C - 1; c >= 0; --c) { 
                if (s3[r + c] == s1[r]) {
                    dp[r][c] = dp[r][c] || dp[r + 1][c];
                }
                if (s3[r + c] == s2[c]) {
                    dp[r][c] = dp[r][c] || dp[r][c + 1];
                }
            }
        }
        return dp[0][0];
    }
};
