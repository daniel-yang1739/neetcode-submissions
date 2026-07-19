class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp_max(nums.size(), 0);
        vector<int> dp_min(nums.size(), 0);
        int prevMax = nums[0], prevMin = nums[0];
        int maxP = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int maxPrevP = prevMax * nums[i];
            int minPrevP = prevMin * nums[i];
            prevMax = max(nums[i], max(maxPrevP, minPrevP));
            prevMin = min(nums[i], min(maxPrevP, minPrevP));
            maxP = max(maxP, prevMax);
        }
        return maxP;
    }
};
