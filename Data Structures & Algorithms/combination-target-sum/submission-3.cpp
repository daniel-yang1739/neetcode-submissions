class Solution {
public:
    void back_tracking(
        int i, int target,
        vector<int>& nums,
        vector<int>& curr_set,
        vector<vector<int>>& res
    ) {
        if (i >= nums.size() || target < 0) return;
        if (target == 0) {
            res.push_back(curr_set);
            return;
        }
        // include nums[i]
        curr_set.push_back(nums[i]);
        back_tracking(i, target - nums[i], nums, curr_set, res);  // allow duplicated
        // not include nums[i]
        curr_set.pop_back();
        back_tracking(i + 1, target, nums, curr_set, res);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr_set;
        back_tracking(0, target, nums, curr_set, res);
        return res;
    }
};
