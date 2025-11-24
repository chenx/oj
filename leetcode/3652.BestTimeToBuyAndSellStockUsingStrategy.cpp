// From: https://medium.com/@svardan41/leetcode-logic-3652-best-time-to-buy-and-sell-stock-using-strategy-dbbb5b5d8861
// prefix/suffix sums + sliding window
//
typedef long long ll;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll res=0;
        int n=prices.size();

        vector<pair<ll,ll>>ps(n); // {the actual strategy, values assuming all the strategies are 1}
        vector<pair<ll,ll>>ss(n); // {actual strategy, values assuming all the strategies are 1}

        res = prices[0]*strategy[0];

        ps[0].first = res;
        ps[0].second = prices[0];

        ss[n-1].first = prices[n-1]*strategy[n-1];
        ss[n-1].second = prices[n-1];

        for(int i = 1; i < n; ++ i){
            res += prices[i]*strategy[i];
            ps[i].first = res;
            ps[i].second += prices[i] + ps[i-1].second;
        }
        for(int i = n-2; i >= 0; -- i){
            ss[i].first = prices[i]*strategy[i] + ss[i+1].first;
            ss[i].second = prices[i] + ss[i+1].second;
        }

        for(int i = 0; i <= n-k; ++ i) {
            //The window starts from i
            ll preRes = (i-1>=0) ? ps[i-1].first : 0;
            ll suffRes = (i+k<n) ? ss[i+k].first : 0;
            ll w_r = ps[i+k-1].second - ps[i+k/2-1].second;
            res = max(res, preRes + suffRes + w_r);
        }
        return res;
    }
};


/**
3652. Best Time to Buy and Sell Stock using Strategy
Medium

You are given two integer arrays prices and strategy, where:

    prices[i] is the price of a given stock on the ith day.
    strategy[i] represents a trading action on the ith day, where:
        -1 indicates buying one unit of the stock.
        0 indicates holding the stock.
        1 indicates selling one unit of the stock.

You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

    Selecting exactly k consecutive elements in strategy.
    Set the first k / 2 elements to 0 (hold).
    Set the last k / 2 elements to 1 (sell).

The profit is defined as the sum of strategy[i] * prices[i] across all days.

Return the maximum possible profit you can achieve.

Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.
 */
