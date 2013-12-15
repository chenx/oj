//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 4/6/2012
//
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


//
// This works too and is more clear. 
// Difference from the first solution is take x == X and y == Y conditions out. 
//
class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> v;
        if (matrix.size() == 0 || matrix[0].size() == 0) return v;
        
        int m = matrix.size();
        int n = matrix[0].size();

        int x = 0, y = 0, X = m-1, Y = n-1, i, j;
        
        while (x <= X && y <= Y) {
            for (i = x, j = y; j <= Y; ++ j) v.push_back(matrix[i][j]);
            for (i = x+1, j = Y; i <= X; ++ i) v.push_back(matrix[i][j]);
            if (x == X) break;
            for (i = X, j = Y-1; j >= y; -- j) v.push_back(matrix[i][j]);
            if (y == Y) break;
            for (i = X-1, j = y; i > x ; -- i)  v.push_back(matrix[i][j]);
            
            ++ x, -- X, ++ y, -- Y;
        }
        
        return v;
    }
};


/*
Problem:

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