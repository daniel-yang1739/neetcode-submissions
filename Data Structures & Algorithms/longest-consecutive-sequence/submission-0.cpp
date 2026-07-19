class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        vector<int> start_nums;
        for (int num : nums) {
            if (nums_set.find(num - 1) == nums_set.end()) {
                start_nums.push_back(num);
            }
        }
        int max_len = 0; 
        for (int num : start_nums) {
            int len = 1;
            while (nums_set.find(++num) != nums_set.end()) ++len;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
