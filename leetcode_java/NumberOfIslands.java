public class Solution {
    private int rows;
    private int cols;
    
    public int numIslands(char[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        
        rows = grid.length; 
        cols = grid[0].length;

        int ct = 0;
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (grid[i][j] == '1') {
                    ++ ct;
                    flip(grid, i, j);
                }
            }
        }

        return ct;
    }
    
    private void flip(char[][] grid, int i, int j) {
        grid[i][j] = '0';
        
        if (i > 0 && grid[i-1][j] == '1') flip(grid, i-1, j);
        if ((i < rows-1) && grid[i+1][j] == '1') flip(grid, i+1, j);
        if (j > 0 && grid[i][j-1] == '1') flip(grid, i, j-1);
        if ((j < cols-1) && grid[i][j+1] == '1') flip(grid, i, j+1);
    }
}

/**
Number of Islands
Difficulty: Medium

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3
 */
