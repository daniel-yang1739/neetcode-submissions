class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> res(nums_size, 1);
        int prefix = 1;
        for (int i = 0; i < nums_size; ++i) {
            res[i] *= prefix;
            prefix *= nums[i];
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
