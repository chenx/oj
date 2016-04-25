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


// Works. Tested.
// Similar to the iterative method of Combinations, w/o constraint on k.
class Solution5 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();
        if (n == 0) return ans; // ok without this too.

        sort(nums.begin(), nums.end()); 
        
        ans.push_back(vector<int>());
        for (int i = 0; i < n; ++ i) {
            for (int j = 0, lenj = ans.size(); j < lenj; ++ j) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        
        return ans;
    }
};

// This works too. Use DFS.
class Solution4 {
public:
    // Note that for every element it has two options: 
    // 1. Either it is in set. 2. or it is NOT in set.
    // From: https://oj.leetcode.com/discuss/13304/simple-solution-using-backtracking
    // Also see: 
    // - http://tech-wonderland.net/blog/leetcode-subset-i-and-ii.html
    // - https://shepherdyuan.wordpress.com/2014/08/01/subset-combination-combination-sum/
    // - http://www.cnblogs.com/fightformylife/p/4118071.html
    void findsub(vector<vector<int> > &res, vector<int> &s, vector<int> &v, int i)
    {
        if (i == s.size()) {
            res.push_back(v);
            return;
        }

        findsub(res, s, v, i+1); // not in set.

        v.push_back(s[i]);
        findsub(res, s, v, i+1); // in set.
        v.pop_back();   
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        sort(S.begin(), S.end());
        vector<int> v;
        findsub(res, S,v, 0);
        return res;
    }
};

// This works too.
// From: https://oj.leetcode.com/discuss/21002/share-my-recursive-and-iterative-solutions
// In essence this uses BFS. ans[1...] is a queue. Each time go through the queue.
// Refer to: http://www.cnblogs.com/Xylophone/p/3915101.html
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans(1, vector<int>());
        sort(S.begin(), S.end());
    
        vector<int> tmp;
        for (int i = 0; i < S.size(); ++i) {
            int len = ans.size();
            for (int j = 0; j < len; ++j) {
                tmp = ans[j];
                tmp.push_back(S[i]);
                ans.push_back(tmp);
            }
        }
    
        return ans;
    }
};

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

// This works. Uses the concept of power set.
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
