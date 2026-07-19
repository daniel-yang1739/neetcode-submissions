class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_freq;
        for (int num : nums) ++num_to_freq[num];
        // bucket sort
        vector<vector<int>> freq_nums(nums.size() + 1);
        for (auto& pair : num_to_freq) {
            freq_nums[pair.second].push_back(pair.first);
        }
        vector<int> ret;
        for (int i = freq_nums.size() - 1; i >= 0; --i) {
            for (int num : freq_nums[i]) {
                ret.push_back(num);
                if (ret.size() == k) {
                    return ret;
                }
            }
        }
        return {};
    }
};
