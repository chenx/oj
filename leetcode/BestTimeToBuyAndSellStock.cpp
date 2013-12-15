/*
   Say you have an array for which the ith element is the price of a 
   given stock on day i.

   If you were only permitted to complete at most one transaction 
   (ie, buy one and sell one share of the stock), design an algorithm 
   to find the maximum profit.
*/

#include <iostream>
#include <vector>
using namespace std;
//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/22/2012
// @Last modified: 12/23/2012
//

// 
// a2 <= a <= b.
// if current element n - a2 > b - a, update a and b;
// otherwise, if n < a2, update a2.
// O(n) in time.
//
class Solution {
public:

    // This works, and is the best method.
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int p = 0; // profit
        int m = prices[0]; // min element
        
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] - m > p) p = prices[i] - m;
            if (prices[i] < m) m = prices[i];
        }
        
        return p;
    }
    
    // This works. This is equivalent to maxProfit_WithIndex().
    // Can be shorter if only keep max_val and a2, instead of b, a and a2.
    int maxProfit_v2(vector<int> &prices) {
        // find min and max element, where max is behind min.
        int len = prices.size();
        if (len <= 1) return 0;
        
        int a, b, a2, n;        
        a2 = a = prices[0];
        b = prices[1];
        if (b < a) a = a2 = b;
    
        // loop invariable: a2 <= a <= b.
        for (int i = 2; i < len; i ++) {
            n = prices[i];
            if (n - a2 > b - a) {
                a = a2;
                b = n;
            } else {
                if (n < a2) a2 = n;
            }
        }
        
        return b - a;
    }
           
    // this version added index book-keeping.
    int maxProfit_WithIndex(vector<int> &prices) {
        // find min and max element, where max is behind min.
        int len = prices.size();
        if (len <= 1) return 0;
        
        int a, b, a2, n;        
        int ia, ib, ia2;
        a2 = a = prices[0];
          ia2 = ia = 0;
        b = prices[1];
          ib = 1;
        if (b < a) {
          a = a2 = b;
            ia = ia2 = ib;
        }
    
        // loop invariant: a2 <= a <= b.
        for (int i = 2; i < len; i ++) {
            n = prices[i];
            if (n - a2 > b - a) {
                a = a2;
                b = n;
                  ia = ia2, ib = i;
            } else {
                if (n < a2) {
                  a2 = n;
                  ia2 = i;
                }
            }
        }
        
        printf("ia = %d, ib = %d; a = %d, b= %d\n", ia, ib, a, b);
        
        return b - a;
    }
};

vector<int> makeVec(int a[], int len) {
    vector<int> v;
    for (int i = 0; i < len; i ++) {
        v.push_back(a[i]);
    }
    return v;
}

int main() {
    int a[] = {9,9,0,3,0,7,7,7,4,1,5,0,1,7};
    int len = sizeof(a) / sizeof(int);
    Solution s;
    vector<int> v = makeVec(a, len);
    cout << s.maxProfit( v ) << endl;
    return 0;
}


/*
http://www.mitbbs.com/article_t1/JobHunting/32256685_0_2.html
luckynoob:
          
    int maxProfit(vector<int> &p) { // buy and sell only time
        if(p.empty()) return 0;
        int m = 0, lm = p[0];
        for(int i = 1; i < p.size(); ++i) {
            if(p[i] > p[i-1]) m = max(m, p[i] - lm);
            else lm = min(lm, p[i]);
        }
        return m;
    }

// 1/13/2013
// This one works and probably is the most clear to understand.
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        
        int mp = 0, minv = prices[0];
        for (int i = 1; i < prices.size(); ++ i) {
            mp = max(mp, prices[i] - minv);
            minv = min(minv, prices[i]);
        }
        return mp;
    }
};
*/
