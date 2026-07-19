class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, max_profit = 0;
        for (int right = 1; right < prices.size(); ++right) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                max_profit = max(
                    max_profit, prices[right] - prices[left]);
            }
        }
        return max_profit;
    }
};
