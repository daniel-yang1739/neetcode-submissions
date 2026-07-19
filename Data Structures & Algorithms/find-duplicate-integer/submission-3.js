class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    findDuplicate(nums) {
        for (let i = 0; i < nums.length; ++i) {
            const index = Math.abs(nums[i]);
            if (nums[index] < 0) return index;
            nums[index] *= -1;
        }
        return -1;
    }
}
