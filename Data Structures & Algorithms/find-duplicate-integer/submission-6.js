class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    findDuplicate(nums) {
        let slow = nums[0], fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow === fast) break;
        }
        let slow2 = nums[0];
        while (true) {
            if (slow === slow2) break;
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow2;
    }
}