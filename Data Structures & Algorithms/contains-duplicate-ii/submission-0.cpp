class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (window.count(nums[i])) {
                return true;
            }
            if (i - k >= 0) {
                window.erase(nums[i - k]);
            }
            window.insert(nums[i]);
        }
        return false;
    }
};