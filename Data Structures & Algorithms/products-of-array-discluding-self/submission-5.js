class Solution {
    /**
     * @param {number[]} nums
     * @return {number[]}
     */
    productExceptSelf(nums) {
        const numsLen = nums.length;
        const res = new Array(numsLen).fill(1);
        let prefix = 1;
        for (let i = 0; i < numsLen; ++i) {
            res[i] *= prefix;
            prefix *= nums[i];
        }
        let postfix = 1;
        for (let i = numsLen - 1; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
}
