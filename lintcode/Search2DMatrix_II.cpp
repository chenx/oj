class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */

    int searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), ct = 0;
        
        for (int i = 0, j = n-1; i < m && j >= 0; ) {
            if (matrix[i][j] == target) ++ ct;

            if (matrix[i][j] <= target) ++ i; // "<" works too.
            else -- j;
        }
        return ct;
    }
};


/**
Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix, 
return the occurrence of it.

This matrix has the following properties:

    Integers in each row are sorted from left to right.
    Integers in each column are sorted from up to bottom.
    No duplicate integers in each row or column.

Example

Consider the following matrix:

[
  [1, 3, 5, 7],
  [2, 4, 7, 8],
  [3, 5, 9, 10]
]

Given target = 3, return 2.
Challenge

O(m+n) time and O(1) extra space

 */
