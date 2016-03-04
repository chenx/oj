// Works. Tested. Improved from Solution, but much better to understand.
// But it's still not very obvious on 2nd statement in for loop.
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        vector<int> mp(n+1, 0); // mp[0] = 0.
        int minv = prices[0];
        
        for (int i = 1; i < n; ++ i) {
            mp[i+1] = max(mp[i], prices[i] - minv);
            minv = min(minv, prices[i] - mp[i-1]); // why so?
        }
        
        return mp[n];
    }
};

// Works.
// https://leetcode.com/discuss/81433/simple-explanation-based-basic-math-state-machine-attached
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> dp(n + 1);
        int maxv = - prices[0];
        for (int i = 1; i < n; ++ i) {
            dp[i + 1] = max(dp[i], maxv + prices[i]);
            maxv = max(dp[i - 1] - prices[i], maxv);
        }

        return dp[n];
    }
};

/**
Best Time to Buy and Sell Stock with Cooldown
Difficulty: Medium

Say you have an array for which the ith element is the price of 
a given stock on day i.

Design an algorithm to find the maximum profit. You may complete 
as many transactions as you like (ie, buy one and sell one share 
of the stock multiple times) with the following restrictions:

    You may not engage in multiple transactions at the same time 
    (ie, you must sell the stock before you buy again).
    
    After you sell your stock, you cannot buy stock on next day. 
    (ie, cooldown 1 day)

Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

 */
