class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (furthest < i) {
                return false;
            }
            furthest = max(furthest, i + nums[i]);
        } 
        return furthest >= nums.size() - 1;
    }
};
