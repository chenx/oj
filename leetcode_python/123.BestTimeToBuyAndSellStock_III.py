class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        A = [0]*n
        B = [0]*n

        A[0] = 0
        low = prices[0]
        for i in range(1, n):
            A[i] = max(A[i-1], prices[i] - low)
            low = min(low, prices[i])

        B[n-1] = 0
        high = prices[n-1]
        for i in range(n-2, -1, -1):
            B[i] = max(B[i+1], high - prices[i])
            high = max(high, prices[i])

        result = 0
        for i in range(n):
            result = max(result, A[i] + B[i])
        return result


/**
123. Best Time to Buy and Sell Stock III
Hard

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 */
