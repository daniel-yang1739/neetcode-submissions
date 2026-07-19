class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (target > sum || target < -sum) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(sum * 2 + 1, 0));
        int R = dp.size(), C = dp[0].size();
        dp[0][nums[0] + sum] = 1;
        dp[0][-nums[0] + sum] += 1;
        for (int r = 1; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (c - nums[r] >= 0) {
                    dp[r][c] += dp[r - 1][c - nums[r]];
                }
                if (c + nums[r] < C) {
                    dp[r][c] += dp[r - 1][c + nums[r]];
                }
            }
        }
        return dp[R - 1][target + sum];
    }
};
