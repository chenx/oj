// Works too. Modified from Solution and Solution2.
class Solution3 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2 || k == 0) return 0;
        
        int mp = 0, ct = 0;
        for (int i = 1; i < n; ++ i) {
            int p = prices[i] - prices[i-1];
            if (p > 0) {
                mp += p;
                ++ ct;
            }
        }
        if (ct <= k) return mp;
        
        // else
        vector<int> curProfit(n, 0), prevProfit(n, 0);
        int minv;
        
        for (int i = 0; i < k; ++ i) {
            minv = prices[0];
            for (int j = 1; j < n; ++ j) {
                curProfit[j] = max(curProfit[j-1], prices[j] - minv);
                minv = min(minv, prices[j] - prevProfit[j-1]);
            }
            prevProfit = curProfit;
        }
        
        return curProfit[n-1];
    }
};


// Works too. Tested.
// From: https://leetcode.com/discuss/69276/c-implementation-dynamic-programming
class Solution2 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1 || k<1) return 0;

        int temp = 0;
        int count = 0;
        int i;
        for(i=1; i<n; i++) {
            if(prices[i] - prices[i-1] > 0) {
                temp = temp + prices[i] - prices[i-1];
                count = count + 1;
            }
        }

        if(count < k) return temp; 
        // When k is big, DP might be time consuming

        vector<int> curProfit(n, 0);
        vector<int> preProfit(n, 0);

        for(int j=0, lowCost; j<k; j++)
        {
            lowCost = prices[0];
            for(i=1; i<n; i++)
            {
                if(curProfit[i-1] < prices[i] - lowCost)
                    curProfit[i] = prices[i] - lowCost;
                else
                    curProfit[i] = curProfit[i-1];

                if(prices[i]-preProfit[i-1] < lowCost)
                    lowCost = prices[i]-preProfit[i-1];
            }
            preProfit = curProfit;
        }
        return curProfit[n-1];
    }
};


/*
If k >= n/2, we can have transactions any time, it can be solved by O(n).
else, we can do it in DP. It can be solved by O(kn).

Use dp[k][i+1] represents, The max profit of using [0,i] data and k transactions.
So we have:

dp[k][i+1] = max(dp[k-1][i+1], dp[k][i], max( dp[k-1][j] + prices[i] - prices[j] ))
  = max(dp[k-1][i+1], dp[k][i], prices[i] + max( dp[k-1][j] - prices[j] )) { 0 <= j < i }
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
Difficulty: Hard

Say you have an array for which the ith element is the 
price of a given stock on day i.

Design an algorithm to find the maximum profit. You may 
complete at most k transactions.

Note:
You may not engage in multiple transactions at the same 
time (ie, you must sell the stock before you buy again).
 */
