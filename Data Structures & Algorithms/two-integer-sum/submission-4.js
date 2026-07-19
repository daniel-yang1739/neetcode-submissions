class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        const numToIndex = new Map();
        for (let i = 0; i < nums.length; ++i) {
            const diff = target - nums[i];
            if (numToIndex.has(diff) === true) {
                return [numToIndex.get(diff), i];
            }
            numToIndex.set(nums[i], i);
        }
        return [];
    }
}
