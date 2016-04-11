// Works too. Start from bottom left corner, go top right.
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
     
        for (int i = m - 1, j = 0; i >= 0 && j < n; ) {
            int v = matrix[i][j];
            if (v == target) return true;
            else if (v < target) ++ j;
            else -- i;
        }   
        
        return false;
    }
};

// This is Young's tableau.
// Start from top right corner, go bottom left.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int rows = matrix.size(), cols = matrix[0].size();
        
        for (int i = 0, j = cols - 1; i < rows && j >= 0; ) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) ++ i;
            else -- j;
        }
        
        return false;
    }
};


/**
Search a 2D Matrix II
Difficulty: Medium

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.
 */
