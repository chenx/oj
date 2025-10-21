/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const n = prices.length;
    if (n == 0) return 0;

    let maxProfit = 0;
    for (let i = 1; i < n; ++ i) {
        let p = prices[i] - prices[i - 1];
        if (p > 0) maxProfit += p;
    }
    return maxProfit;
};
