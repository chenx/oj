class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        DP = [0] * (1 + amount)
        DP[0] = 1

        for i in range(len(coins)):
            for j in range(coins[i], 1 + amount):
                DP[j] += DP[j - coins[i]]
        
        return DP[amount]

/**
518. Coin Change II
Medium

You are given an integer array coins representing coins of different denominations and an integer 
amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made 
up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
 */
