class Solution {
public:
    void back_tracking(
        int curr, 
        unordered_set<int> included,
        vector<int>& permutation,
        vector<int>& nums,
        vector<vector<int>>& res
    ) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (included.count(nums[i])) {
                continue;
            }
            permutation.push_back(nums[i]);
            included.insert(nums[i]);
            back_tracking(i, included, permutation, nums, res);
            included.erase(nums[i]);
            permutation.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> included;
        vector<vector<int>> res;
        vector<int> permutation;
        back_tracking(0, included, permutation, nums, res);
        return res;
    }
};
