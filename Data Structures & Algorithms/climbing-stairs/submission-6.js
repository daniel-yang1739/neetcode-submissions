class Solution {
    /**
     * @param {number} n
     * @return {number}
     */
    climbStairs(n) {
        if (n <= 2) return n;
        let last2 = 1, last1 = 2;
        for (let i = 2; i < n; ++i) {
            const tmp = last2 + last1;
            last2 = last1;
            last1 = tmp;
        }
        return last1;
    }
}
