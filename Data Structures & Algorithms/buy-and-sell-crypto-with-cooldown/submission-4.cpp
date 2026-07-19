class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // state: 0 -> can buy, 1 -> hold
        int size = prices.size();
        vector<vector<int>> dp(size + 1, vector<int>(2, 0));
        for (int i = size - 1; i >= 0; --i) {
            dp[i][0] = max(
                dp[i + 1][1] - prices[i],  // buy
                dp[i + 1][0]  // no buy
            );
            dp[i][1] = max(
                (i + 2 < size) ? dp[i + 2][0] + prices[i] : prices[i],  // no sell
                dp[i + 1][1]  // no sell
            );
        }
        return dp[0][0];
    }
};
