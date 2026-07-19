class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        
        // Rob first house (can't rob last house)
        vector<int> dp1(size);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size - 1; ++i) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }
        
        // Don't rob first house (can rob last house)
        vector<int> dp2(size);
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for (int i = 3; i < size; ++i) {
            dp2[i] = max(dp2[i - 2] + nums[i], dp2[i - 1]);
        }
        
        return max(dp1[size - 2], dp2[size - 1]);
    }
};
