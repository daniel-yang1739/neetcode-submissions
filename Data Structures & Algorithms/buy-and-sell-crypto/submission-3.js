class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */
    maxProfit(prices) {
        let left = 0, maxProfit = 0;
        for (let right = 1; right < prices.length; ++right) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                maxProfit = Math.max(
                    maxProfit, prices[right] - prices[left]);
            }
        }
        return maxProfit;
    }
}
