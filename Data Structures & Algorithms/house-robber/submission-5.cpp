class Solution {
public:
    int rob(vector<int>& nums) {
        int last2 = 0, last1 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int curr_max = max(last2 + nums[i], last1);
            last2 = last1;
            last1 = curr_max;
        }
        return last1;
    }
};
