//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 4/6/2012
//

// Works too.
class Solution4 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size(); // rows
        if (rows == 0) return ans;
        int cols = matrix[0].size(); // columns

        int m = 0, n = 0, M = rows, N = cols, i, j;
        while (m < M && n < N) {
            for (j = n; j < N; j ++) ans.push_back(matrix[m][j]);
            for (i = m + 1; i < M; i ++) ans.push_back(matrix[i][N-1]);
            if (m == M - 1) break;
            for (j = N - 2; j >= n; j --) ans.push_back(matrix[M-1][j]);
            if (n == N - 1) break;
            for (i = M - 2; i > m; i --) ans.push_back(matrix[i][n]);
            m ++, n++, M --, N --;
        }
        return ans;
     }
};

//
// Works. Best so far.  More clear. 
// Difference from the first solution is take x == X and y == Y conditions out. 
//
class Solution3 {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;

        int x = 0, y = 0, X = matrix.size() - 1, Y = matrix[0].size() - 1;
        
        while(x <= X && y <= Y) {
            for (int i = x, j = y; j <= Y; ++ j) ans.push_back(matrix[i][j]);
            for (int i = x+1, j = Y; i <= X; ++ i) ans.push_back(matrix[i][j]);
            if (x == X) break;
            for (int i = X, j = Y-1; j >= y; -- j) ans.push_back(matrix[i][j]);
            if (y == Y) break;
            for (int i = X-1, j = y; i > x; -- i) ans.push_back(matrix[i][j]);
            
            ++ x, ++ y, -- X, -- Y;
        }
        
        return ans;
    }
};


// This works too.
class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.size() == 0 || matrix[0].size() == 0) return v;
        int x = 0, y = 0, X = matrix.size() - 1, Y = matrix[0].size() - 1, i, j;

        while (x <= X && y <= Y) {
            for (i = x, j = y; j <= Y; ++ j) v.push_back(matrix[i][j]);

            for (-- j, ++ i; i <= X; ++ i) v.push_back(matrix[i][j]);

            if (-- i == x) break; // be careful here.
            for (-- j; j >= y; -- j) v.push_back(matrix[i][j]);

            if (++ j == Y) break; // be careful here.
            for (-- i; i > x; -- i) v.push_back(matrix[i][j]);

            ++ x; -- X; ++ y; -- Y;
        }
        
        return v;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> v;
        if (matrix.size() == 0 || matrix[0].size() == 0) return v;
        int x = 0, X = matrix.size() - 1, 
            y = 0, Y = matrix[0].size() - 1, i, j;
        while (x <= X && y <= Y) {
            // print top row.
            for (i = x, j = y; j <= Y; j ++) v.push_back(matrix[i][j]);
            // print right edge.
            for (i = x + 1, j = Y; i <= X; i ++) v.push_back(matrix[i][j]);
            // print bottom row.
            for (i = X, j = Y - 1; j >= y && i > x; j --) v.push_back(matrix[i][j]);
            // print left edge.
            for (i = X - 1, j = y; i > x && j < Y; i --) v.push_back(matrix[i][j]);
    
            x ++, X --, y ++, Y --;
        }
        return v;
    }
};

/**
Spiral Matrix
Difficulty: Medium

Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
 */
