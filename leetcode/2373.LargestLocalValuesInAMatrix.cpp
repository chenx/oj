// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n-2, vector<int>(n-2, 0));

        for (int i = 0; i < n - 2; ++ i) {
            for (int j = 0; j < n - 2; ++ j) {
                result[i][j] = INT_MIN;
                for (int x = i; x < i + 3; ++ x) {
                    for (int y = j; y < j + 3; ++ y) {
                        result[i][j] = max(result[i][j], grid[x][y]);
                    }
                }
            }
        }
        return result;
    }
};


/**
2373. Largest Local Values in a Matrix
Easy

You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

    maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around 
    row i + 1 and column j + 1.

In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.

 

Example 1:

Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
Output: [[9,9],[8,6]]
 */
