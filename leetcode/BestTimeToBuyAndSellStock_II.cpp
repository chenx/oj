//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/22/2012
// @Last modified: 12/22/2012
//
/*
 * Note: Add up every incremental step.
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
        int s = 0;
        
        for (int i = 1; i < prices.size(); i ++) {
            s += max(0, prices[i] - prices[i-1]);
        }
        
        return s;
    }
};
