class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(
            nums[0],  // for single-element array
            max(helper(nums1), helper(nums2))
        );
    }

    int helper(vector<int>& nums) {
        int last2 = 0, last1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = max(last2 + nums[i], last1);
            last2 = last1;
            last1 = curr;
        }
        return last1;
    }
};
