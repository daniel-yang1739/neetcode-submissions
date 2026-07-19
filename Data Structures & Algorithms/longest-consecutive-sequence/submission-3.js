class Solution {
    /**
     * @param {number[]} nums
     * @return {number}
     */
    longestConsecutive(nums) {
        const numsSet = new Set(nums);
        let maxLen = 0;
        for (let num of nums) {
            if (!numsSet.has(num - 1)) {
                let length = 1;
                while (numsSet.has(num + length)) ++length;
                maxLen = Math.max(maxLen, length);
            }
        }
        return maxLen;
    }
}
