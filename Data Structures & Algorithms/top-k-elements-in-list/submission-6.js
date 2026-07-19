class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    topKFrequent(nums, k) {
        let numToFreq = {}
        nums.forEach((num) => {            
            numToFreq[num] = (numToFreq[num] ?? 0) + 1;
        });
        const freqNums = new Array(nums.length + 1).fill(0).map(() => []);
        Object.entries(numToFreq).forEach(([num, freq]) => {
            freqNums[freq].push(parseInt(num));
        });
        const ret = []
        for (let i = freqNums.length - 1; i >= 0; --i) {
            for (let num of freqNums[i]) {
                ret.push(num);
                if (ret.length == k) return ret;
            }
        }
        return ret;
    }
}
