
/*
if k >= n/2, we can have transactions any time, it can be solved by O(n).

else, we can do it in DP.

use dp[k][i+1] represents, The max profit of using [0,i] data and k transactions.

So we have:

dp[k][i+1] = max(dp[k-1][i+1], dp[k][i], max( dp[k-1][j] + prices[i] - prices[j] ))

= max(dp[k-1][i+1], dp[k][i], prices[i] + max( dp[k-1][j] - prices[j] )) { 0 <= j < i }

it can be solved by O(kn).
*/

// This works. 
// From https://oj.leetcode.com/discuss/25627/dp-o-kn-time-o-n-space-cpp-solution
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int size = (int)prices.size();
        if (k==0||size<2) {
            return 0;
        }
        if (k>size/2) {
            int sum = 0;
            for(int i = 1;i < size;i++){
                if(prices[i] > prices[i-1]){
                    sum += prices[i] - prices[i-1];
                }
            }
            return sum;
        }
        vector<int> buy(k,INT_MIN);
        vector<int> sell(k,0);
        for (int i=0; i<size; i++) {
            for (int j=k-1; j>=0; j--) {
                sell[j]=max(sell[j],buy[j]+prices[i]);
                buy[j]=max(buy[j],(j>0?sell[j-1]:0)-prices[i]);
            }
        }
        return sell[k-1];        
    }
};

/**
Best Time to Buy and Sell Stock IV 

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */