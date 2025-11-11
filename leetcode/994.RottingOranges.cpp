// See: https://leetcode.com/problems/rotting-oranges/editorial/
// BFS. 
// Time Complexity: O(N^2 * M^2) where N×M is the size of the input grid.
// - In the in-place BFS traversal, for each round of BFS, we would have to iterate through the entire grid.
// Space: O(1)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size(), time = 2;

        while(bfs(grid, time, m, n)) {
            ++ time;
        }

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return time - 2;
    }

    bool bfs(vector<vector<int>>& grid, int time, int m, int n) {
        static vector<int> directions = {-1, 0, 1, 0, -1};
        bool hasGoodApple = false;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] != time) continue;

                for (int k = 0; k < 4; ++ k) {
                    int x = i + directions[k], y = j + directions[k+1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (grid[x][y] == 1) {
                            hasGoodApple = true;
                            grid[x][y] = time + 1;
                        }
                    }
                }
            }
        }
        return hasGoodApple;
    }
};

/**
994. Rotting Oranges
Medium

You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 */
