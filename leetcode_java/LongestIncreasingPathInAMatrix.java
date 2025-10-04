class Solution {
    private int m, n, maxLen = 0;
    
    public int longestIncreasingPath(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;
        int[][] DP = new int[m][n];
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                maxLen = Math.max(maxLen, getPath(matrix, DP, i, j));
            }
        }
        
        return maxLen;
    }
    
    private int getPath(int[][] matrix, int[][] DP, int i, int j) {
        if (DP[i][j] > 0) return DP[i][j];
                
        int maxLen = 0;
        for (int k = 0; k < dirs.length - 1; ++ k) {
            int x = i + dirs[k], y = j + dirs[k+1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (matrix[x][y] > matrix[i][j]) {
                    int len = getPath(matrix, DP, x, y);
                    maxLen = Math.max(len, maxLen);
                }
            }
        }
        
        return DP[i][j] = maxLen + 1;
    }
                                  
    private int[] dirs = {-1, 0, 1, 0, -1};
}

/**
329. Longest Increasing Path in a Matrix

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally 
or move outside the boundary (i.e., wrap-around is not allowed).
 */
