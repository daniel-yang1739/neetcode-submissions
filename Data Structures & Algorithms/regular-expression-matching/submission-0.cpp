class Solution {
public:
    bool isMatch(string s1, string s2) {
        int R = s1.length(), C = s2.length();
        vector<vector<bool>> dp(R + 1, vector<bool>(C + 1, false));
        dp[0][0] = true;  // initialize
        for (int r = 0; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                int idx1 = r - 1, idx2 = c - 1;
                if (s2[idx2] == '*') {
                    dp[r][c] = (
                        (
                            (
                                s1[idx1] == s2[idx2 - 1] || 
                                s2[idx2 - 1] == '.' 
                            ) && 
                            (r > 0 && dp[r - 1][c]) || 
                            dp[r][c - 2]
                        )
                    );
                } else {
                    dp[r][c] = (
                        (s1[idx1] == s2[idx2] || s2[idx2] == '.') && 
                        r > 0 && dp[r - 1][c - 1]
                    );
                }
            }
        }
        return dp.back().back();
    }
};
