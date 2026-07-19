class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> dp(s.length() + 1);
        dp[s.length()] = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (
                    i + 1 < s.length() &&
                    s[i] == '1' || s[i] == '2' &&
                    s[i + 1] < '7'
                ) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};
