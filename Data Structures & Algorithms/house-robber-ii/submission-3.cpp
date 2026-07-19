class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        int max_money = 0;
        // Rob first house (don't rob last house)
        int last2 = 0, last1 = 0;
        for (int i = 0; i < size - 1; ++i) {
            int curr = max(last2 + nums[i], last1);
            last2 = last1;
            last1 = curr;
        }
        max_money = last1;
        // Don't rob first houst (rob last houst)
        last2 = 0, last1 = 0;
        for (int i = 1; i < size; ++i) {
            int curr = max(last2 + nums[i], last1);
            last2 = last1;
            last1 = curr;
        }
        return max(max_money, last1);
    }
};
