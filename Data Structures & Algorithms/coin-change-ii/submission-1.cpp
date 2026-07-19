class Solution {
public:
    int backtracking(
        int idx, int target, vector<int>& coins,
        vector<vector<int>>& memo
    ) {
        if (target == 0) return 1;
        if (idx == coins.size() || target < 0) return 0;
        if (memo[idx][target] != 0) {
            return memo[idx][target];
        }
        int noCurr = backtracking(
            idx + 1, target, coins, memo);
        int getCurr = backtracking(
            idx, target - coins[idx], coins, memo);
        return memo[idx][target] = noCurr + getCurr;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, 0));
        return backtracking(0, amount, coins, memo);
    }
};
