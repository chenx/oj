/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const n = prices.length;
    if (n <= 1) return 0;

    let low = prices[0], maxProfit = 0;
    for (let i = 1; i < n; ++ i) {
        maxProfit = Math.max(maxProfit, prices[i] - low);
        low = Math.min(low, prices[i]);
    }
    return maxProfit;
};
