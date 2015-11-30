//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/4/2013
// @Last modified: 1/4/2013
//

// This works too.
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int L = 0, R = matrix.size() - 1, M;
        while (L <= R) {
            M = L + (R-L)/2;
            if (matrix[M][0] == target) return true;
            else if (matrix[M][0] < target) L = M + 1;
            else R = M - 1;
        }
        
        int row = R; // <- !!!
        if (row < 0) return false;
        
        L = 0, R = matrix[0].size() - 1;
        while (L <= R) {
            M = L + (R-L)/2;
            if (matrix[row][M] == target) return true;
            else if (matrix[row][M] < target) L = M + 1;
            else R = M - 1;
        }
        
        return false;
    }
};

class Solution {
public:
    // log(row) + log(column) solution.
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // first search in first column, then search in the row.
        int rows = matrix.size();
        if (rows == 0) return false;
        int cols = matrix[0].size();
        if (cols == 0) return false;
                
        // Be careful: for 1st column, it is matrix[mid][0].
        int left = 0, right = rows - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == matrix[mid][0]) return true;
            else if (target > matrix[mid][0]) left = mid + 1;
            else right = mid - 1;
        }
        
        // now left is the insertion point, left - 1 is the row to search for.
        int row = left - 1;
        if (row < 0) return false; // left = 0. Less than smallest element in matrix.
        
        // Be careful: for row-th row, it is matrix[row][mid].
        left = 0; right = cols - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == matrix[row][mid]) return true;
            else if (target > matrix[row][mid]) left = mid + 1;
            else right = mid - 1;
        }
        
        return false;
    }
};

/*
Problem:

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */
