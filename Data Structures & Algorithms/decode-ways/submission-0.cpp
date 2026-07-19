class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        vector<int> dp(s.length(), 0);
        dp[0] = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            int num = stoi(s.substr(i - 1, 2));
            if (num >= 10 && num <= 26) {
                dp[i] += i == 1 ? 1 : dp[i - 2];
            }
        }
        return dp.back();
    }
};
