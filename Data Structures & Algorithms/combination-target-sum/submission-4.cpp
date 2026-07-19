class Solution {
public:
    void back_tracking(
        int i, int target,
        vector<int>& nums,
        vector<int>& curr_set,
        vector<vector<int>>& res
    ) {
        if (target == 0) {
            res.push_back(curr_set);
            return;
        }
        for (int j = i; j < nums.size(); ++j) {
            if (target - nums[j] < 0) return;
            curr_set.push_back(nums[j]);
            back_tracking(j, target - nums[j], nums, curr_set, res);
            curr_set.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr_set;
        back_tracking(0, target, nums, curr_set, res);
        return res;
    }
};
