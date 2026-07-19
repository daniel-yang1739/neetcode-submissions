class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.size() + 1, 0);
        int size = dp.size();
        for (int c = size - 2; c >= 0; --c) {
            dp[c] = dp[c + 1] + 1;
        }
        for (int r = word1.size() - 1; r >= 0; --r) {
            int prevDiag = dp[size - 1];
            dp[size - 1] += 1;
            for (int c = size - 2; c >= 0; --c) {
                int temp = dp[c];
                if (word1[r] == word2[c]) {
                    dp[c] = prevDiag;
                } else {
                    // {replace, delete, insert}
                    dp[c] = min({prevDiag, dp[c], dp[c + 1]}) + 1;
                }
                prevDiag = temp;
            }
        }
        return dp[0];
    }
};
