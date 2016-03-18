// Works. Tested.
class Solution3 {
public:
    int longestIncreasingPath(const vector<vector<int>>& matrix) {
                if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        this->m = matrix.size(), this->n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                maxLen = max(maxLen, getPath(matrix, dp, i, j));
            }
        }
        
        return maxLen;
    }
    
private:    
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    
    int getPath(const vector<vector<int>>& matrix, vector<vector<int>> &dp, int x, int y) {
        if (dp[x][y] > 0) return dp[x][y];
        
        int len = 1;
        
        for (int i = 0; i < dirs.size(); ++ i) {
            int dx = x + dirs[i][0], dy = y + dirs[i][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                if (matrix[dx][dy] > matrix[x][y]) {
                    len = max(len, 1 + getPath(matrix, dp, dx, dy));
                }
            }
        }
        
        return dp[x][y] = len;
    }    
};

// Works. Tested. Modified from: 
// https://leetcode.com/discuss/84319/clean-c-solution-using-dfs-with-memoization-dp
class Solution2 {
public:
    Solution() {
        dir = {make_pair(-1,0), make_pair(0,-1), make_pair(1,0), make_pair(0,1)};
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        m = matrix.size(); n = matrix[0].size(); 
        int maxLen = -1;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                maxLen = max(maxLen, getLen(matrix, i, j, dp));
            }
        }
        
        return maxLen;
    }
    
    int getLen(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> & dp) {
        if (dp[i][j] != -1) return dp[i][j]; // This avoid timeout!!!

        // maxLen default must be 1: if none of 4 paths work, it's still valid 1.
        int maxLen = 1; 
        for (int k = 0; k < 4; ++ k) { // be careful, don't use i, since i is a param.
            int di = i + dir[k].first, dj = j + dir[k].second;
            if (di >= 0 && di < m && dj >= 0 && dj < n && matrix[di][dj] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + getLen(matrix, di, dj, dp));
            }
        }
        
        dp[i][j] = maxLen;
        return maxLen;
    }
private:
    int m, n;
    vector<pair<int, int>> dir; 
};

// Should work. But times out for large input.
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxLen = 0;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int len = 0;
                getLen(matrix, i, j, len, maxLen);
            }
        }
        
        return maxLen;
    }
    
    void getLen(vector<vector<int>>& matrix, int i, int j, int len, int &maxLen) {
        int m = matrix.size(), n = matrix[0].size();
        
        ++ len;
        maxLen = max(len, maxLen);
        
        int cur = matrix[i][j];
        if (i > 0 && matrix[i-1][j] > cur) getLen(matrix, i-1, j, len, maxLen);
        if (i < m-1 && matrix[i+1][j] > cur) getLen(matrix, i+1, j, len, maxLen);
        if (j > 0 && matrix[i][j-1] > cur) getLen(matrix, i, j-1, len, maxLen);
        if (j < n-1 && matrix[i][j+1] > cur) getLen(matrix, i, j+1, len, maxLen);
    }
};


/**
Longest Increasing Path in a Matrix
Difficulty: Medium

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up 
or down. You may NOT move diagonally or move outside of the boundary 
(i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]

Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]

Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */
