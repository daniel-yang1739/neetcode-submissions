class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        vector<int> newNums(N + 2, 1);
        for (int i = 1; i <= N; ++i) {
            newNums[i] = nums[i - 1];
        }

        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
        for (int l = N; l >= 1; --l) {
            for (int r = l; r <= N; ++r) {
                for (int i = l; i <= r; ++i) {
                    int coins = (
                        newNums[l - 1] * newNums[i] * newNums[r + 1] +
                        dp[l][i - 1] + dp[i + 1][r]
                    );
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }
        
        return dp[1][N];
    }
};
