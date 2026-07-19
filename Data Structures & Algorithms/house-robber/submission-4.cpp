class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        int last2 = nums[0], last1 = max(nums[0], nums[1]);
        int curr_max = 0;
        for (int i = 2; i < size; ++i) {
            curr_max = max(last2 + nums[i], last1);
            last2 = last1;
            last1 = curr_max;
        }
        return curr_max;
    }
};
