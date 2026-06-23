//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//
#include <iostream>

using namespace std;

// Works. Best so far.
class Solution4 {
public:
    int totalNQueens(int n) {
        int total = 0;
        vector<int> board(n, 0);
        solve(total, board, 0);
        return total;
    }

    void solve(int& total, vector<int>& board, int row) {
        if (board.size() == row) {
            ++ total;
            return;
        }

        for (int i = 0; i < board.size(); ++ i) {
            board[row] = i;
            if (! hasConflict(board, row)) solve(total, board, row+1);
        }
    }

    bool hasConflict(vector<int>& board, int row) {
        for (int i = 0; i < row; ++ i) {
            if (board[i] == board[row]) return true;
            if (abs(board[row] - board[i]) == row - i) return true;
        }

        return false;
    }
};

//
// For large test set, will time out so far.
// use iteration?
//
class Solution {
public:
    int totalNQueens(int n) {
        int * a = new int[n];
        for (int i = 0; i < n; i ++) a[i] = 0;
        
        int result = 0;
        q(a, n, 0, result);
        
        return result;
    }
    
    void q(int a[], int n, int level, int & result) {
        for (int i = 0; i < n; i ++) {
            a[level] = i;
            
            // find conf.
            int conf = 0;
            for (int ii = 0; !conf && ii <= level - 1; ii ++) {
              int jj;
              for (jj = ii + 1; jj <= level; jj ++) {
                if (a[ii] == a[jj] ||
                    ((a[ii] - a[jj]) == (ii - jj) || (a[ii] - a[jj]) == (jj - ii)) ) {
                    conf = 1;
                    break;
                }
              }
            }

            if (! conf) {
                if (level + 1 == n) result += 1;
                else q(a, n, level + 1, result);
            }
        }
    }
        
};


//
// This  works. Passes both test sets.
// Major difference: conflict() test is incremental.
//
class Solution2 {
public:
    int totalNQueens(int n) {
        int ans = 0;
        int s[n];
        
        solve(ans, s, n, 0);
        return ans;
    }
    
    void solve(int & ans, int s[], int n, int pos) {
        if (n == pos) {
            ++ ans;
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            if (! conflict(s, i, pos)) {
                s[pos] = i;
                solve(ans, s, n, pos+1);
            }
        }
        
    }
    
    // new index: s[pos] = i. old indices: s[j] for j = 0, ..., pos-1.
    inline bool conflict(int s[], int i, int pos) {
        for (int j = 0; j < pos; ++ j) {
            if (i == s[j] || ( pos-j == i-s[j] || pos-j == s[j]-i)) return true;
        }
        return false;
    }
};

// This also works. Passes all tests. 11/17/2014
class Solution3 {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> a(n);
        solve(ans, a, n, 0);
        return ans;
    }
    
    void solve(int &ans, vector<int> a, int n, int pos) {
        if (n == pos) {
            ++ ans;
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            a[pos] = i + 1;
            if (! hasConflict(a, pos)) {
                solve(ans, a, n, pos+1);
            }
        }
    }
    
    bool hasConflict(vector<int> &a, int pos) {
        for (int i = 0; i < pos; ++ i) {
            if (a[i] == a[pos] || abs(a[i] - a[pos]) == pos-i) return true;
        }
        return false;
    }    
};

int main() {
    Solution s;
    int r = s.totalNQueens(12);
    cout << r << " answers found" << endl;
    
    return 0;
}

/*

class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int * a = new int[n];
        for (int i = 0; i < n; i ++) a[i] = 0;
        
        int result = 0;
        q(a, n, 0, result);
        
        return result;
    }
    
    void q(int a[], int n, int level, int & result) {
        for (int i = 0; i < n; i ++) {
            a[level] = i;
            if (! conflict(a, level)) {
                if (level + 1 == n) result += 1;
                else q(a, n, level + 1, result);
            }
        }
    }
        
    bool conflict(int a[], int level) {
        int i, j;
        for (i = 0; i <= level - 1; i ++) {
            for (j = i + 1; j <= level; j ++) {
                if (a[i] == a[j]) return true;
                if (abs(a[i] - a[j]) == abs(i - j)) return true;
            }
        }
        return false;
    }    
};
*/

