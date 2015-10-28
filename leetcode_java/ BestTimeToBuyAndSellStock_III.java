public class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if (len <= 1) return 0;
        
        int mv = prices[0];
        int mp1[] = new int[len];
        mp1[0] = 0;
        for (int i = 1; i < len; ++ i) {
            mp1[i] = Math.max(mp1[i-1], prices[i] - mv);
            mv = Math.min(mv, prices[i]);
        }
        
        mv = prices[len - 1];
        int mp2[] = new int[len];
        mp2[len - 1] = 0;
        for (int i = len - 2; i >= 0; -- i) {
            mp2[i] = Math.max(mp2[i+1], mv - prices[i]);
            mv = Math.max(mv, prices[i]);
        }
        
        int max_profit = 0;
        for (int i = 0; i < len; ++ i) {
            max_profit = Math.max(max_profit, mp1[i] + mp2[i]);
        }
        
        return max_profit;
    }
}

/**
Best Time to Buy and Sell Stock III
Difficulty: Hard

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
