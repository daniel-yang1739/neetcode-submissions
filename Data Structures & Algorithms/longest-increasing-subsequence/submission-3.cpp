class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> increasing;
        increasing.push_back(nums[0]);
        int maxLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (increasing.back() < nums[i]) {
                increasing.push_back(nums[i]);
                ++maxLen;
                continue;
            }
            int idx = lower_bound(
                increasing.begin(), increasing.end(), nums[i]
            ) - increasing.begin();
            increasing[idx] = nums[i];
        }
        return maxLen;
    }
};
