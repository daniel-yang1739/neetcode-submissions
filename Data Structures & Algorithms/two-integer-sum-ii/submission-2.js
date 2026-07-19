class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(numbers, target) {
        let left = 0, right = numbers.length - 1;
        while (left < right) {
            let sum = numbers[left] + numbers[right];
            if (sum < target) ++left;
            else if (sum > target) --right;
            else return [left + 1, right + 1];
        }
    }
}
