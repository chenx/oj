
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if (n <= 1 or k == 0):
            return 0
        
        cur = [0] * n
        prev = [0] * n

        while k > 0:
            k -= 1
            low = prices[0]
            for i in range(1, n):
                # print(f"{i}:  cur[i-1]={cur[i-1]}, prices[i]={prices[i]}, low = {low}")
                cur[i] = max(cur[i-1], prices[i] - low)
                low = min(low, prices[i] - prev[i-1])
            
            prev = cur[:]  ## copying array needs to use slice!!!
        
        return cur[n-1]


# 0 0 2 2 2 3 3 4 
# 0 0 2 2 2 5 5 6 

# 1: {cur[i-1]}=0, prices[i]=3, low=3
# 2: {cur[i-1]}=0, prices[i]=5, low=3
# 3: {cur[i-1]}=2, prices[i]=0, low=3
# 4: {cur[i-1]}=2, prices[i]=0, low=0
# 5: {cur[i-1]}=2, prices[i]=3, low=0
# 6: {cur[i-1]}=3, prices[i]=1, low=0
# 7: {cur[i-1]}=3, prices[i]=4, low=0
# 0 0 2 2 2 3 3 4 
# 1: {cur[i-1]}=0, prices[i]=3, low=3
# 2: {cur[i-1]}=0, prices[i]=5, low=3
# 3: {cur[i-1]}=2, prices[i]=0, low=3
# 4: {cur[i-1]}=2, prices[i]=0, low=-2
# 5: {cur[i-1]}=2, prices[i]=3, low=-2
# 6: {cur[i-1]}=5, prices[i]=1, low=-2
# 7: {cur[i-1]}=5, prices[i]=4, low=-2
# 0 0 2 2 2 5 5 6 


/**
188. Best Time to Buy and Sell Stock IV
Hard

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: 
i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
 */
