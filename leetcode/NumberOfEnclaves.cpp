class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // For every land cell on the border, BFS to mark all as -1,
        // then count remaining land cells whose value is 1.
        // Time: O(m*n), space: O(1).

        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++ i) { // first and last column.
            if (grid[i][0] == 1) markCells(grid, i, 0);
            if (grid[i][n-1] == 1) markCells(grid, i, n-1);
        }
        for (int j = 1; j < n-1; ++ j) { // first and last row.
            if (grid[0][j] == 1) markCells(grid, 0, j);
            if (grid[m-1][j] == 1) markCells(grid, m-1, j);
        }

        int ct = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) ++ ct;
            } 
        }
        return ct;
    }

    void markCells(vector<vector<int>>& grid, int i, int j) {
        static vector<int> dir = {-1, 0, 1, 0, -1};

        if (grid[i][j] != 1) return;
        grid[i][j] = -1;
        for (int k = 0; k < 4; ++ k) {
            int x = i + dir[k], y = j + dir[k+1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (grid[x][y] == 1) markCells(grid, x, y);
            }
        }
    }
};

/**
1020. Number Of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking
off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
 */
