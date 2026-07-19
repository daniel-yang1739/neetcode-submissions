class Solution {
public:
    int backtracking(
        int day, int state, vector<int>&prices,
        vector<vector<int>>& memo
    ) {
        // state: 0 -> can buy, 1 -> hold
        if (day >= prices.size()) {
            return 0;
        }
        if (memo[state][day] != -1) {
            return memo[state][day];
        }
        int result;
        if (state == 0) {
            result = max(
                backtracking(day + 1, state, prices, memo),  // no buy
                -prices[day] + backtracking(day + 1, 1, prices, memo)  // buy
            );
        } else {
            result = max(
                backtracking(day + 1, state, prices, memo),  // no sell
                prices[day] + backtracking(day + 2, 0, prices, memo)  // sell
            );
        }
        return memo[state][day] = result;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> memo(2, vector<int>(prices.size(), -1));
        return backtracking(0, 0, prices, memo);
    }
};
