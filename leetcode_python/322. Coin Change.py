class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
            
        DP = [-1] * (1 + amount)

        # coins.sort()
        for i in range(1 + amount):
            for j in range(len(coins)):
                if i < coins[j]:
                    continue
                elif i == coins[j]:
                    DP[i] = 1
                else:
                    if DP[i - coins[j]] > 0:
                        if DP[i] == -1 or DP[i] > 1 + DP[i - coins[j]]:
                            DP[i] = 1 + DP[i - coins[j]]
        
        return DP[amount]

/**
322. Coin Change
Solved
Medium
Topics
conpanies iconCompanies

You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be 
made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
 */
