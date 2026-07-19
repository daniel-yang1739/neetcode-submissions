class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_len = 0;
        for (int num : nums) {
            if (nums_set.find(num - 1) == nums_set.end()) {
                int len = 1;
                while (nums_set.find(++num) != nums_set.end()) ++len;
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
