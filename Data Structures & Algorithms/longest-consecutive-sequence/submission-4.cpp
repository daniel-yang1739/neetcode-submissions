class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num : nums) {
            if (!numSet.count(num - 1)) {
                int len = 1;
                while (numSet.count(++num)) {
                    ++len;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
