class Solution {
private:
    int maxP = 0;
public:
    int backtracking(
        int day, int state, vector<int>&prices
    ) {
        // state: 0 -> can buy, 1 -> hold
        if (day >= prices.size()) {
            return 0;
        }
        int result;
        if (state == 0) {
            result = max(
                backtracking(day + 1, state, prices),  // no buy
                -prices[day] + backtracking(day + 1, 1, prices)  // buy
            );
        } else {
            result = max(
                backtracking(day + 1, state, prices),  // no sell
                prices[day] + backtracking(day + 2, 0, prices)  // sell
            );
        }
        return result;
    }

    int maxProfit(vector<int>& prices) {
        return backtracking(0, 0, prices);
    }
};
