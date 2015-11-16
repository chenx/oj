// Similar to Unique Path problem.

// This works too. 
// Optimized from Solution. 
// No need for another 2D array to store result, just used grid.
public class Solution2 {
    public int minPathSum(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        int rows = grid.length, cols = grid[0].length;
        
        for (int j = 1; j < cols; ++ j) grid[0][j] += grid[0][j-1];
        for (int i = 1; i < rows; ++ i) {
            grid[i][0] += grid[i-1][0];
            
            for (int j = 1; j < cols; ++ j) {
                grid[i][j] += Math.min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[rows-1][cols-1];
    }
}

// This works.
public class Solution {
    public int minPathSum(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        int rows = grid.length, cols = grid[0].length;
        
        int[][] v = new int[rows][cols];
        
        v[0][0] = grid[0][0];
        for (int j = 1; j < cols; ++ j) v[0][j] = grid[0][j] + v[0][j-1];
        for (int i = 1; i < rows; ++ i) {
            v[i][0] = grid[i][0] + v[i-1][0];
            
            for (int j = 1; j < cols; ++ j) {
                v[i][j] = grid[i][j] + Math.min(v[i-1][j], v[i][j-1]);
            }
        }
        
        return v[rows-1][cols-1];
    }
}

/**
Minimum Path Sum
Difficulty: Medium

Given a m x n grid filled with non-negative numbers, find a path 
from top left to bottom right which minimizes the sum of all numbers 
along its path.

Note: You can only move either down or right at any point in time.
 */
