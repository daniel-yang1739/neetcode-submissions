class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ROW = text1.length(), COL = text2.length();
        vector<int> dp(COL + 1, 0);
        for (int r = ROW - 1; r >= 0; --r) {
            int prev_diagonal = 0;
            for (int c = COL - 1; c >= 0; --c) {
                int temp = dp[c];
                if (text1[r] == text2[c]) {
                    dp[c] = prev_diagonal + 1;
                } else {
                    dp[c] = max(dp[c], dp[c + 1]);
                }
                prev_diagonal = temp;
            }
        }
        return dp[0];
    }
};
