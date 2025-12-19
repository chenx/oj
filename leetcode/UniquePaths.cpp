// DFS. Times out for large input.
class Solution4 {
    vector<int> end;
public:
    int uniquePaths(int m, int n) {
        end = {m-1, n-1};

        int pathCount = 0;
        vector<vector<int>> board(m, vector<int>(n, 0));
        dfs(m, n, 0, 0, pathCount, board);
        return pathCount;
    }

    void dfs(int m, int n, int i, int j, int& pathCount, vector<vector<int>>& board) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;

        if (i == end[0] && j == end[1]) {
            ++ pathCount;
            return;
        }

        board[i][j] = 1;

        dfs(m, n, i+1, j, pathCount, board);
        dfs(m, n, i, j+1, pathCount, board);

        board[i][j] = 0;
    }
};

//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 1/21/2013
//

// Works too. Tested. Assume m > 0 and n > 0.
// Initialize matrix to all 1, to avoid initialize first row/column.
class Solution3 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; ++ i) 
            for (int j = 1; j < n; ++ j) 
                v[i][j] = v[i-1][j] + v[i][j-1];

        return v[m-1][n-1];
    }
};

// This works too. 10-26-2014
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;
        
        vector<vector<int> > v(m, vector<int>(n, 0));
        
        // initialize first row.
        for (int j = 0; j < n; ++ j) v[0][j] = 1;
        
        // other rows.
        for (int i = 1; i < m; ++ i) {
            v[i][0] = 1;
            for (int j = 1; j < n; ++ j) {
                v[i][j] = v[i][j-1] + v[i-1][j];
            }
        }
        return v[m-1][n-1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i, j;
        int a[m][n];
        for (j = 0; j < n; j ++) { a[0][j] = 1; }
        
        for (i = 1; i < m; i ++) {
            a[i][0] = 1;
            for (j = 1; j < n; j ++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[m - 1][n - 1];
    }
};

/**
Unique Paths
Difficulty: Medium

A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
 */

// This is the case of can only go by the upper right half of the square.
// The answer is Catalan number: http://en.wikipedia.org/wiki/Catalan_number
class CatalanNum {
public:
    int uniquePaths(int n) {
        int i, j;

        int a[n][n];
        for (j = 0; j < n; j ++) { a[0][j] = 1; }
        
        for (i = 1; i < n; i ++) {
            a[i][i-1] = 0;
            for (j = i; j < n; j ++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[n - 1][n - 1];
    }
};

