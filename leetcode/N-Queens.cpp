// Works too. Tested.
class Solution5 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> v(n, 0);
        solve(ans, v, 0);
        return ans;
    }
    
    void solve(vector<vector<string>> &ans, vector<int> &v, int pos) {
        if (pos == v.size()) {
            ans.push_back(getConfig(v));
            return;
        }
        
        for (int i = 0; i < v.size(); ++ i) { // Note the 3 "pos" here!
            v[pos] = i+1;
            if (! conflict(v, pos)) solve(ans, v, pos+1);
        }
    }
    
    vector<string> getConfig(vector<int> & v) {
        int n = v.size();
        vector<string> u;
        for (int i = 0; i < n; ++ i) {
            string s;
            int j = 1;
            for (; j < v[i]; ++ j) s += ".";
            s += "Q";
            for (++ j; j <= n; ++ j) s += ".";
            u.push_back(s);
        }
        return u;
    }
    
    bool conflict(vector<int> & v, int pos) {
        for (int i = 0; i < pos; ++ i) {
            if (v[i] == v[pos] || pos - i == abs(v[pos] - v[i])) return true;
        }
        return false;
    }
};

//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int a[n];
        for (int i = 0; i < n; i ++) a[i] = 0;
        
        vector<vector<string> > result;
        q(a, n, 0, result);
        
        return result;
    }
       
    void q(int a[], int n, int level, vector<vector<string> > & result) {
        if (level == n) {
            //puts("result found"); 
            vector<string> v; 
            for (int i = 0; i < n; i ++) { v.push_back( getRow(n, a[i]) ); } 
            result.push_back(v);
            return;
        }
        
        for (int i = 0; i < n; i ++) {
            a[level] = i;
            if (! conflict(a, level)) q(a, n, level + 1, result);
        }
    }
    
    // return by value: a copy is returned.
    string getRow(int n, int p) {
        string s;
        for (int i = 0; i < p; i ++) s += ".";
        s += "Q";
        for (int i = p + 1; i < n; i ++) s += ".";
        //printf("result new row: %s\n", s.c_str());
        return s;
    }
    
    bool conflict(int a[], int level) {
        int i, j;
        for (i = 0; i <= level - 1; i ++) {
            for (j = i + 1; j <= level; j ++) {
                if (a[i] == a[j]) return true;
                if (abs(a[i] - a[j]) == j-i) return true;
            }
        }
        return false;
    }
};


// This works too.
class Solution2 {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        int s[n];
        
        solve(ans, s, n, 0);
        return ans;
    }
    
    void solve(vector<vector<string> > & ans, int s[], int n, int pos) {
        if (n == pos) {
            ans.push_back(output(s, n));
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            if (! conflict(s, i, pos)) {
                s[pos] = i; 
                solve(ans, s, n, pos+1);
            }
        }        
    }
    
    //
    // new index: s[pos] = i. old indices: s[j] for j = 0, ..., pos-1.
    // This is simpler than Solution.conflict(): 
    //     previous columns have been checked and don't need to check again.
    //
    bool conflict(int s[], int i, int pos) {
        for (int j = 0; j < pos; ++ j) {
            if (i == s[j] || ( pos-j == i-s[j] || pos-j == s[j]-i)) return true;
        }
        return false;
    }
    
    vector<string> output(int s[], int n) {
        vector<string> ans;
        for (int i = 0; i < n; ++ i) {
            string t = "";
            for (int j = 0; j < s[i]; ++ j) t += ".";
            t += "Q";
            for (int j = s[i]+1; j < n; ++ j) t += ".";
            ans.push_back(t);
        }
        return ans;
    }
};

// This works. too. 11/17/2014
class Solution3 {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<int> a(n);
        solve(ans, a, n, 0);
        return ans;
    }
    
    void solve(vector<vector<string> > &ans, vector<int> a, int n, int pos) {
        if (n == pos) {
            ans.push_back( getMatrix(a, n) );
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            a[pos] = i + 1;
            if (! hasConflict(a, pos)) {
                solve(ans, a, n, pos+1);
            }
            //a[pos] = 0; // not needed.
        }
    }
    
    vector<string> getMatrix(vector<int> &a, int n) {
        vector<string> v;
        for (int i = 0; i < n; ++ i) {
            string s = "";
            for (int j = 1; j < a[i]; ++ j) { s += "."; }
            s += "Q";
            for (int j = a[i] + 1; j <= n; ++ j) { s += "."; }
            v.push_back(s);
        }
        return v;
    }
    
    bool hasConflict(vector<int> &a, int pos) {
        for (int i = 0; i < pos; ++ i) {
            if (a[i] == a[pos] || abs(a[i] - a[pos]) == pos-i) return true;
        }
        return false;
        /*
        // no need to use double loop. can use the fact that (a, pos-1) is conflict-free, to check only the last one.
        for (int i = 0; i < pos-1; ++ i) {
            for (int j = i+1; j < pos; ++ j) {
                if (a[i] == a[j] || abs(i-j) == abs(a[i] - a[j])) return true;
            }
        }
        return false;
        */
    }
};

// This works too. Seems best so far.
class Solution4 {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> v(n, 0);
        solve(ans, v, 0, n);
        return ans;
    }
    
    void solve(vector<vector<string>> &ans, vector<int> &v, int pos, int n) {
        if (pos == n) {
            vector<string> u;
            for (int i = 0; i < n; ++ i) { // string(int n, char c): cc..c
                string s = string(v[i] - 1, '.') + "Q" + string(n - v[i], '.');
                u.push_back(s);
            }
            ans.push_back(u);
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            v[pos] = i + 1;
            if (! conflict(v, pos)) solve(ans, v, pos + 1, n);
        }
    }
    
    bool conflict(vector<int> &v, int pos) {
        for (int i = 0; i < pos; ++ i) {
            if (v[i] == v[pos] || pos - i == abs(v[pos] - v[i])) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<string> > r = s.solveNQueens(4);
    
    for (int i = 0; i < r.size(); i ++) {
        vector<string> u = r[i];
        for (int j = 0; j < u.size(); j ++) {
            cout << u[j] << endl;
        }
        puts("");
    }

    return 0;
}


/**
N-Queens
Difficulty: Hard

The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 */
 
