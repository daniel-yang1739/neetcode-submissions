class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_cost = prices[0];
        for (int& sell : prices) {
            max_profit = max(max_profit, sell - min_cost);
            min_cost = min(min_cost, sell);
        }
        return max_profit;
    }
};
