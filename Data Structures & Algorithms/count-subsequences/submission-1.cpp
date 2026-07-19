class Solution {
public:
    int numDistinct(string s, string t) {
        int R = s.length(), C = t.length();
        vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));
        
        for (int r = 0; r <= R; ++r) {
            dp[r][C] = 1;
        }

        for (int r = R - 1; r >= 0; --r) {
            for (int c = C - 1; c >= 0; --c) {
                dp[r][c] = dp[r + 1][c];  // not to use char s[r]
                if (s[r] == t[c]) {
                    dp[r][c] += dp[r + 1][c + 1];  // use char s[r]
                }
            }
        }

        return dp[0][0];
    }
};
