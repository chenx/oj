// Brute force.
// Time: O(n * 3^m)
class Solution {
    int m;
    int n;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        
        m = matrix.size();
        n = matrix[0].size();
        for (int j = 0; j < n; ++ j) {
            getPath(matrix, 0, minSum, 0, j);
        }
        return minSum;
    }

    void getPath(vector<vector<int>>& matrix, int sum, int& minSum, int row, int col) {
        if (row == matrix.size()) {
            if (sum < minSum) {
                minSum = sum;
            }
            return;
        }

        sum += matrix[row][col];
        getPath(matrix, sum, minSum, row + 1, col);
        if (col > 0) getPath(matrix, sum, minSum, row + 1, col - 1);
        if (col < n-1) getPath(matrix, sum, minSum, row + 1, col + 1);
    }
};


/**
931. Minimum Falling Path Sum
Medium
Topics
conpanies iconCompanies

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that 
is either directly below or diagonally left/right. Specifically, the next element from position 
(row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
 */
