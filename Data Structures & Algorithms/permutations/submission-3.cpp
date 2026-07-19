class Solution {
public:
    void back_tracking(
        vector<bool>& included,
        vector<int>& permutation,
        vector<int>& nums,
        vector<vector<int>>& res
    ) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (included[i]) {
                continue;
            }
            permutation.push_back(nums[i]);
            included[i] = true;
            back_tracking(included, permutation, nums, res);
            included[i] = false;
            permutation.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> included(nums.size(), false);
        vector<vector<int>> res;
        vector<int> permutation;
        back_tracking(included, permutation, nums, res);
        return res;
    }
};
