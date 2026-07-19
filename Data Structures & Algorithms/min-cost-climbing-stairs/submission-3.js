class Solution {
    /**
     * @param {number[]} cost
     * @return {number}
     */
    minCostClimbingStairs(cost) {
        const costSize = cost.length;
        const dp = new Array(costSize + 1).fill(0);
        for (let i = 2; i < costSize + 1; ++i) {
            dp[i] = Math.min(
                dp[i - 1] + cost[i - 1],
                dp[i - 2] + cost[i - 2]
            )
        }
        return dp.pop()
    }
}
