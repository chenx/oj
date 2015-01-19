//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// This works too.
class Solution2 {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        int n = S.size();
        int len = 1 << n;
        sort(S.begin(), S.end());
        
        for (int i = 0; i < len; ++ i) {
            vector<int> v;
            for (int j = 0; j < n; ++ j) {
                if (i & (1 << j)) {
                    v.push_back(S[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// This works.
// This is good in run time.
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        
        sort(S.begin(), S.end());
        
        int n = S.size();
        int np = (int) pow((double)2, (double)n);
        
        for (int i = 0; i < np; i ++) {
            vector<int> v;
            for (int j = 0, shift = 1; j <= i; j ++) {
                if (i & shift) { 
                    v.push_back(S[j]); // output S[i];
                }
                shift <<= 1;
            }
            result.push_back(v);
        }
        
        return result;
    }
};

/*
// Timeout for large test set.
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        
        sort(S.begin(), S.end());
        
        int n = S.size();
        int np = (int) pow((double) 2, (double) n);
        
        for (int i = 0; i < np; i ++) {
            vector<int> v;
            for (int j = 0; j <= i; j ++) {
                if (i & (1 << j)) {
                    // output S[i];
                    v.push_back(S[j]);
                }
            }
            result.push_back(v);
            cout << endl;
        }
        
        return result;
    }
};
*/

int main() {
    Solution s;
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    s.subsets(v);
    return 0;    
}

/*
Problem:
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
