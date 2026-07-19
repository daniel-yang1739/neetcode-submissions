class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
     */
    hasDuplicate(nums) {
        let numsSet = new Set(nums);
        return numsSet.size < nums.length;
    }
}
