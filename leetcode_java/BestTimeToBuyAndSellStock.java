public class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if (len <= 1) return 0;
        
        int min_p = prices[0];
        int max_p = 0;
        
        for (int i = 1; i < len; ++ i) {
            max_p = Math.max(prices[i] - min_p, max_p);
            min_p = Math.min(min_p, prices[i]);
        }
        
        return max_p;
    }
}

/**
Best Time to Buy and Sell Stock
Difficulty: Medium

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
