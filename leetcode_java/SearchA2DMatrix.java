public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) return false;
        
        int L = 0, R = matrix.length - 1, M;
        while (L <= R) {
            M = L + (R-L)/2;
            if (matrix[M][0] == target) return true;
            else if (matrix[M][0] < target) L = M + 1;
            else R = M - 1;
        }
        
        int row = R; // or L - 1.
        if (row < 0) return false;
        
        L = 0; R = matrix[0].length - 1;
        while (L <= R) {
            M = L + (R-L)/2;
            if (matrix[row][M] == target) return true;
            else if (matrix[row][M] < target) L = M + 1;
            else R = M - 1;
        }
        
        return false;        
    }
}

/**
Search a 2D Matrix
Difficulty: Medium

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
