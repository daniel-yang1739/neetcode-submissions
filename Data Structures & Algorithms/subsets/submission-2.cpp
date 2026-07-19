class Solution {
public:
    void back_tracking(
        int i, 
        vector<int>& nums,
        vector<int>& curr_set, 
        vector<vector<int>>& subsets
    ) {
        if (i >= nums.size()) {
            subsets.push_back(curr_set);
            return;
        }
        // include nums[i]
        curr_set.push_back(nums[i]);
        back_tracking(i + 1, nums, curr_set, subsets);
        // not include nums[i]
        curr_set.pop_back();
        back_tracking(i + 1, nums, curr_set, subsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curr_set;
        back_tracking(0, nums, curr_set, subsets);
        return subsets;
    }
};
