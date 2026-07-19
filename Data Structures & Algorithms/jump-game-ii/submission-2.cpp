class Solution {
public:
    int jump(vector<int>& nums) {
        int furthest = 0, jumpCount = 0, currEnd = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            furthest = max(furthest, i + nums[i]);
            if (i == currEnd) {
                ++jumpCount;
                currEnd = furthest;
            }
        }
        return jumpCount;
    }
};
