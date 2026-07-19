class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int target = nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] < -target) ++left;
                else if (nums[left] + nums[right] > -target) --right;
                else {
                    s.insert({target, nums[left], nums[right]});
                    ++left;
                }
            }
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};
