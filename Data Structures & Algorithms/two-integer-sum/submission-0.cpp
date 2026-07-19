class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;
        for (int i = 0; i < nums.size(); ++i) {
            if (
                num_to_index.find(target - nums[i]) != num_to_index.end()
            ) {
                return {num_to_index[target - nums[i]], i};
            } else {
                num_to_index[nums[i]] = i;
            }
        }
    }
};
