class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int res = N;
        for (int i = 0; i < N; ++i) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
