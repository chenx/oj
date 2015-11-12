public class Solution {
    public int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        
        int [][] s = new int[m][n];
        
        for (int j = 0; j < n; ++ j) s[0][j] = 1;
        for (int i = 0; i < m; ++ i) s[i][0] = 1;
        
        for (int i = 1; i < m; ++ i) {
            for (int j = 1; j < n; ++ j) {
                s[i][j] = s[i-1][j] + s[i][j-1];
            }
        }
        
        return s[m-1][n-1];
    }
}

/**
Unique Paths
Difficulty: Medium

A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
 */
