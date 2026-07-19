class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int R = nums.size(), C = sum / 2;
        vector<vector<bool>> dp(R + 1, vector<bool>(C + 1, false));
        for (int r = 0; r <= R; ++r) {
            dp[r][0] = true;
        }
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                int idx = r - 1;
                dp[r][c] = dp[r - 1][c];
                if (nums[idx] <= c) {
                    dp[r][c] = dp[r][c] || dp[r - 1][c - nums[idx]];
                }
            }
        }
        return dp[R][C];
    }
};
