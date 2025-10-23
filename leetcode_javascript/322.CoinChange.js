/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    if (amount === 0) return 0;
    const DP = Array(amount + 1).fill(-1);  // need to be -1, not 0.

    for (let i = 1; i <= amount; ++ i) {
        for (let j = 0; j < coins.length; ++ j) {
            if (i < coins[j]) {
                continue;
            } else if (i === coins[j]) {
                DP[i] = 1;
                break;
            } else {
                if (DP[i - coins[j]] > 0) {
                    if (DP[i] === -1 || DP[i] > 1 + DP[i - coins[j]]) {
                        DP[i] = 1 + DP[i - coins[j]];
                    }
                }
            }
        }
    }
    return DP[amount];
};
