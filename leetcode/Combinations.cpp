//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//
#include <vector>
using namespace std;

// Works. Tested. Iterative. By: XC. 2/24/2016.
// Intuitive idea: e.g. combine(3, 2), the process is:
// cycle 1: {1}
// cycle 2: {1}, {1,2}->add, {2}
// cycle 3: {1}, {2}, {1,3}->add, {2,3}->add, {3}.
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans, sets;
        
        if (k == 0) return ans;
        if (k == 1) {
            for (int i = 1; i <= n; ++ i) ans.push_back(vector<int>(1, i));
            return ans;
        }
        
        for (int i = 1; i <= n; ++ i) {
            for (int j = 0, lenj = sets.size(); j < lenj; ++ j) {
                int len = sets[j].size();
                if (len < k - 1) {
                    sets.push_back(sets[j]);
                    sets.back().push_back(i);
                }
                else if (len == k - 1) {
                    ans.push_back(sets[j]);
                    ans.back().push_back(i);
                }
            }
            sets.push_back(vector<int>(1, i));
        }
        
        return ans;
    }
};

// This works too. Iterative version.
class Solution2 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> p(k, 0);
        while (i >= 0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k - 1) result.push_back(p);
            else {
                ++i;
                p[i] = p[i - 1];
            }
        }
        return result;        
    }
};

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        int * a = new int[n];
        for (int i = 0; i < n; i ++) a[i] = 0;
                
        comb(a, n, k, 0, result);
        return result;
    }

    
    // Optimized from c_nm.
    // Note, if use vector<int> S, then can pass as reference instead of copy, to save space. 
    // I.e., signature is: void comb(vector<int>  &S, int n, int m, int start, vec<vec<int> > &vs)
    void comb(int S[], int n, int m, int start, vector<vector<int> > &vs) {
        if (m == 0) {
            vector<int> v;
            for (int i = 0; i < n; ++ i) {
                if (S[i] == 1) { v.push_back(i+1); }
            }
            vs.push_back(v);
            return;
        }
        
        for (int i = start; i < n; ++ i) {
            S[i] = 1;
            comb(S, n, m - 1, i + 1, vs);
            S[i] = 0;
        }
    }
    
    void comb2(int in[], int out[], int mn, int mx, 
        int pos, int m, vector<vector<int> > &vs) {
            
        if (pos == m) {
            vector<int> v;
            for (int i = 0; i < m; ++ i) v.push_back(out[i]);
            vs.push_back(v);
            return;
        }
        
        for (int i = mn; i < mx; ++ i) {
            out[pos] = in[i];
            comb2(in, out, i+1, mx+1, pos+1, m, vs); // note: i+1, not mn+1!!!
        }
        
    }
        
    void c_nm(int a[], int n, int m, int start, vector<vector<int> > & result) {
        if (m <= 0 || m > n || n <= 0 || start < 0) return;
    
        for (int i = start; i < n; i ++) {
            a[i] = 1;
            m --;
            if (m > 0) { c_nm(a, n, m, i+1, result); }
            else { //output(a, n);     
                vector<int> v;
                for (int j = 0; j < n; j ++) {
                    if (a[j] == 1) v.push_back(j+1);
                }
                result.push_back(v);
            }
            a[i] = 0;
            m ++;
        }
    }

};

int main() {
    Solution s;
    vector<vector<int> > v = s.combine(4,2);

    for (int i = 0; i < v.size(); i ++) {
        vector<int> u = v[i];
        for (int j = 0; j < u.size(); j ++) {
            printf("%d ", u[j]);
        }
        puts("");
    }
    puts("");  
                 
    return 0;
}


/**
Combinations 

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */
