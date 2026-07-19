class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (target > sum || target < -sum) return 0;
        vector<int> prev(sum * 2 + 1, 0);
        int R = nums.size(), C = prev.size();
        prev[nums[0] + sum] += 1;
        prev[-nums[0] + sum] += 1;  // '+=' to avoid nums[0] is 0
        for (int r = 1; r < R; ++r) {
            vector<int> curr(C, 0);
            for (int c = 0; c < C; ++c) {
                if (c - nums[r] >= 0) {
                    curr[c] += prev[c - nums[r]];
                }
                if (c + nums[r] < C) {
                    curr[c] += prev[c + nums[r]];
                }
            }
            prev = curr;
        }
        return prev[target + sum];
    }
};
