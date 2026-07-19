class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp_max(nums.size(), 0);
        vector<int> dp_min(nums.size(), 0);
        dp_max[0] = nums[0], dp_min[0] = nums[0];
        int maxP = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int maxPrevP = dp_max[i - 1] * nums[i];
            int minPrevP = dp_min[i - 1] * nums[i];
            dp_max[i] = max(nums[i], max(maxPrevP, minPrevP));
            dp_min[i] = min(nums[i], min(maxPrevP, minPrevP));
            maxP = max(maxP, dp_max[i]);
        }
        return maxP;
    }
};
