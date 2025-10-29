class Solution {
    int area;

    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length, maxArea = 0;

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    area = 0;
                    dfs(grid, i, j);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void dfs(int[][] grid, int i, int j) {
        grid[i][j] = 2;
        ++ area;

        for (int k = 0; k < 4; ++ k) {
            int x = i + directions[k], y = j + directions[k+1];

            if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                if (grid[x][y] == 1) {
                    dfs(grid, x, y);
                }
            }
        }
    }

    int[] directions = {-1, 0, 1, 0, -1};
}

/**
695. Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the 
grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
 */
