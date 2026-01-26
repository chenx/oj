//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/22/2012
// @Last modified: 12/23/2012
//

/*
 * DP. Is the max of 0/1 transaction and 2 transactions (divided at pos 0, ... , len-1).
 * For complex test set, this runs out of time limit for the last test case,
 * which has 26003 entries, but the result is correct (4).
 */

#include <iostream>
#include <vector>
using namespace std;

// Generalized from solution of "188. Best Time to Buy and Sell Stock IV"
// See: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Time: O(kn) = O(2n) = O(n)
// Space: O(n)
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> cur(n), prev(n);
        for (int k = 2; k > 0; -- k) {
            int low = prices[0];
            for (int i = 1; i < n; ++ i) {
                cur[i] = max(cur[i-1], prices[i] - low);
                low = min(low, prices[i] - prev[i-1]);
            }
            prev = cur;
        }
        return cur[n-1];
    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> A(n, 0), B(n, 0);

        A[0] = 0;
        int low = prices[0];
        for (int i = 1; i < n; ++ i) {
            A[i] = max(A[i-1], prices[i] - low);
            low = min(low, prices[i]);
        }

        B[n-1] = 0;
        int high = prices[n-1];
        for (int i = n-2; i >= 0; -- i) {
            B[i] = max(B[i+1], high - prices[i]);
            high = max(high, prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; ++ i) {
            maxProfit = max(maxProfit, A[i] + B[i]);
        }
        return maxProfit;
    }
};

class Solution {
      vector<int> prices;
public:
    // best method, DP. O(n).
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        
        int len = prices.size();
        // Can use this too: int mp1[len], mp2[len]; // just can't initialize since len is not const.
        vector<int> mp1(len), mp2(len);
        int m, i; 
        
        // go forward, obtain max profits
        // m is min value so far.
        mp1[0] = 0;
        m = prices[0];
        for (i = 1; i < len; i ++) {
            mp1[i] = max(mp1[i-1], prices[i] - m);
            m = min(m, prices[i]);
        }
        
        // go backward, obtain max profits
        // m is max value so far.
        mp2[len - 1] = 0;
        m = prices[len - 1];
        for (i = len - 2; i >= 0; i --) {
            mp2[i] = max(mp2[i+1], m - prices[i]);
            m = max(m, prices[i]);
        }
        
        // go through once, obtain max profit.
        // note this includes the case of one transaction.
        // this can be combined into the last loop, like in maxProfit_v3().
        // Question: why not mp1[i] + mp2[i+1]? 
        // Ans: This will ignore the case of only 1 transaction:
        // If the max happens at the boundary for the case mp1[i] + mp2[i], 
        // it's equivalent to 1 transaction.
        int mp = 0;
        for (i = 0; i < len; i ++) {
            mp = max(mp, mp1[i] + mp2[i]);
        }
        
        return mp;
    }
    
    int maxProfit_v3(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        
        int len = prices.size();
        vector<int> mp1(len), mp2(len);
        int m, i; 
        
        // go forward, obtain max profits
        // m is min value so far.
        mp1[0] = 0;
        m = prices[0];
        for (i = 1; i < len; i ++) {
            mp1[i] = max(mp1[i-1], prices[i] - m);
            m = min(m, prices[i]);
        }
        
        // go backward, obtain max profits
        // m is max value so far.
        mp2[len - 1] = 0;
        m = prices[len - 1];
        int mp = mp1[len - 1];
        for (i = len - 2; i >= 0; i --) {
            mp2[i] = max(mp2[i+1], m - prices[i]);
            m = max(m, prices[i]);
            mp = max(mp, mp1[i] + mp2[i]);
        }
                
        return mp;
    }    
    
    // This works, but is slow compared to better method. O(n^2).
    int maxProfit_slow(vector<int> &prices) {
        int len = prices.size();
        if (len <= 1) return 0;

        this->prices = prices;
        int sum, max_sum = max(0, maxProfit1(0, len - 1)); 

        for (int i = 0; i < len; i ++) {
            sum = maxProfit1(0, i) +
                  maxProfit1(i + 1, len - 1);
            if (sum > max_sum) max_sum = sum;
            //printf("i=%d, max_sum=%d\n", i, max_sum);
        }
        return max_sum;
    }

    int maxProfit1(int left, int right) {
        // find min and max element, where max is behind min.
        int len = right - left + 1;
        if (len <= 1) return 0;
        
        int a, b, a2, n;        
        a2 = a = this->prices[left];
        b = this->prices[left + 1];
        if (b < a) a = a2 = b;

        // loop invariable: a2 <= a <= b.
        for (int i = left + 2; i <= right; i ++) {
            n = this->prices[i];
            if (n - a2 > b - a) {
                a = a2;
                b = n;
            } else {
                if (n < a2) a2 = n;
            }
        }
        
        return b - a;
    }
};

vector<int> makeVec(int a[], int len) {
    vector<int> v;
    for (int i = 0; i < len; i ++) v.push_back(a[i]);
    return v;
}

int main() {
    Solution s;
    int a[] = {6,1,3,2,4,7};
    int len = sizeof(a) / sizeof(int);
    vector<int> prices = makeVec(a, len);
    cout << "max profit = " << s.maxProfit(prices);
    return 0;
}

/*
http://www.mitbbs.com/article_t/JobHunting/32256685.html
peking2:

    public int maxProfit(int[] prices) {
        if(prices==null || prices.length==0)
            return 0;
           
        int len=prices.length;
        int[] dp=new int[len];
        int min=prices[0];
        for(int i=1;i<len;i++)
        {
            min=Math.min(min, prices[i]);
            dp[i]=Math.max(dp[i-1],prices[i]-min);
        }
        int ans=dp[len-1];
        int max=prices[len-1];
        dp[len-1]=0;
        for(int i=len-2;i>=0;i--)
        {
            max=Math.max(max,prices[i]);
            int tmp=Math.max(dp[i+1], max-prices[i]);
            ans=Math.max(ans, dp[i]+tmp);
            dp[i]=tmp;
        }
       
        return ans;
    }
*/



