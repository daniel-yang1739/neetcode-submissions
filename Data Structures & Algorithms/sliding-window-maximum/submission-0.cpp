class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> decreasing;
        for (int i = 0; i < nums.size(); ++i) {
            while (!decreasing.empty() && decreasing.back() < nums[i]) {
                decreasing.pop_back();
            }
            decreasing.push_back(nums[i]);
            if (i >= k - 1) {
                res.push_back(decreasing.front());
                if (nums[i - k + 1] == decreasing.front()) {
                    decreasing.pop_front();  
                }
            }
        }
        return res;
    }
};
