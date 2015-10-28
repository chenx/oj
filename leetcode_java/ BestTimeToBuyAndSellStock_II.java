public class Solution {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if (len <= 1) return 0;
        
        int mp = 0;
        
        for (int i = 1; i < len; ++ i) {
            mp += Math.max(0, prices[i] - prices[i-1]);
        }
        
        return mp;
    }
}

/**
Best Time to Buy and Sell Stock II
Difficulty: Medium

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
