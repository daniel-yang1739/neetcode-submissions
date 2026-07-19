class Solution {
private:
    int maxP = 0;
public:
    void backtracking(
        int day, int boughtDay, int profit, vector<int>&prices
    ) {
        if (day >= prices.size()) {
            maxP = max(maxP, profit);
            return;
        }
        if (boughtDay == -1) {
            // no buy
            backtracking(day + 1, boughtDay, profit, prices);
            // buying
            boughtDay = day;
            backtracking(day + 1, boughtDay, profit, prices); 
        } else {
            // no sell
            backtracking(day + 1, boughtDay, profit, prices);
            //selling
            profit += prices[day] - prices[boughtDay];
            boughtDay = -1;
            backtracking(day + 2, boughtDay, profit, prices);
        }
    }

    int maxProfit(vector<int>& prices) {
        backtracking(0, -1, 0, prices);
        return maxP;
    }
};
