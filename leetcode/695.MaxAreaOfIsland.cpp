class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        grid[i][j] = 2;
        ++ area;

        for (int k = 0; k < 4; ++ k) {
            int x = i + directions[k], y = j + directions[k+1];

            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (grid[x][y] == 1) {
                    dfs(grid, x, y, area);
                }
            }
        }
    }

    int directions[5] = {-1, 0, 1, 0, -1};
};


/**
695. Max Area of Island
Medium

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally 
(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
 */
