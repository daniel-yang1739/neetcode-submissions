class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, total = 0;
        for (int num : nums) {
            total += num;
            maxSum = max(maxSum, total);
            total = max(total, 0);
        }
        return maxSum;
    }
};
