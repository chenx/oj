public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid.length == 0 || obstacleGrid[0].length == 0) return 0;
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        
        int [][] s = new int[m][n];
        int i, j;
        
        for (j = 0; j < n; ++ j) {
            if (obstacleGrid[0][j] == 1) break;
            s[0][j] = 1;
        }
        for (; j < n; ++ j) s[0][j] = 0;
        
        for (i = 0; i < m; ++ i) {
            if (obstacleGrid[i][0] == 1) break;
            s[i][0] = 1;
        }
        for (; i < m; ++ i) s[i][0] = 0;
        
        for (i = 1; i < m; ++ i) {
            for (j = 1; j < n; ++ j) {
                s[i][j] = obstacleGrid[i][j] == 1 ? 0 : s[i-1][j] + s[i][j-1];
            }
        }
        
        return s[m-1][n-1];
    }
}

/**
Unique Paths II
Difficulty: Medium

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
