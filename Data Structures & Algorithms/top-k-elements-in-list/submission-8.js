class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        const numToFreq = new Map()
        for (const num of nums) {
            numToFreq.set(num, (numToFreq.get(num) || 0) + 1);
        }
        const freqNums = Array.from({ length: nums.length + 1 }, () => []);
        for (const [num, freq] of numToFreq.entries()) {
            freqNums[freq].push(num);
        }
        const ret = []
        for (let i = freqNums.length - 1; i >= 0; --i) {
            for (const num of freqNums[i]) {
                ret.push(num);
                if (ret.length === k) return ret;
            }
        }
        return ret;
    }
}
