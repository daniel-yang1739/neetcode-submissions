class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> forward(nums_size), backward(nums_size);
        forward[0] = 1, backward[nums_size - 1] = 1;
        for (int i = 0; i < nums_size - 1; ++i) {
            forward[i + 1] = forward[i] * nums[i];
        }
        for (int i = nums_size - 1; i >= 1; --i) {
            backward[i - 1] = backward[i] * nums[i];
        }
        vector<int> res;
        for (int i = 0; i < nums_size; ++i) {
            res.push_back(forward[i] * backward[i]);
        }
        return res;
    }
};
