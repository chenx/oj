// Time: O(mn)
// Space: O(n)
class Solution2 {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int maxCount = 0, rowHits = 0;
        vector<int> colHits(cols, 0);

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                // reset the hits on the row, if necessary.
                if (col == 0 || grid[row][col - 1] == 'W') {
                    rowHits = 0;
                    for (int k = col; k < cols; ++k) {
                        if (grid[row][k] == 'W')
                            // stop the scan when we hit the wall.
                            break;
                        else if (grid[row][k] == 'E')
                            rowHits += 1;
                    }
                }

                // reset the hits on the column, if necessary.
                if (row == 0 || grid[row - 1][col] == 'W') {
                    colHits[col] = 0;
                    for (int k = row; k < rows; ++k) {
                        if (grid[k][col] == 'W')
                            break;
                        else if (grid[k][col] == 'E')
                            colHits[col] += 1;
                    }
                }

                // run the calculation for the empty cell.
                if (grid[row][col] == '0') {
                    maxCount = max(maxCount, rowHits + colHits[col]);
                }
            }
        }

        return maxCount;
    }
};


// Solution 1: Brute force
// Time: O(mn(m+n))
// Space: O(1)

/**
361. Bomb Enemy
Medium

Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies 
you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too 
strong to be destroyed.

 

Example 1:

Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
 */
