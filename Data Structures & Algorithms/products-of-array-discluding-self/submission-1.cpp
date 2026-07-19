class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> res(nums_size, 1);
        for (int i = 1; i < nums_size; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        // the `res` is the prefix product array now, we 
        // can do backward suffix product to get the result.
        int postfix = 1;
        for (int i = nums_size - 1; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};
