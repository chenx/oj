// See https://leetcode.com/problems/number-of-distinct-islands
// Hash the path by traversal directions.
class Solution {
    int m, n;
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        m = grid.size(), n = grid[0].size(); 

        set<string> islands;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    string path;
                    bfs(grid, i, j, path);
                    islands.insert(path);
                }
            }
        }
        return islands.size();
    }

    void bfs(vector<vector<int>>& grid, int i, int j, string& path) {
        grid[i][j] = -1; // mark cell as visited.

        for (int k = 0; k < dirs.size() - 1; ++ k) {
            int x = i + dirs[k], y = j + dirs[k+1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] == 1) {
                    path += pathDir[k];
                    bfs(grid, x, y, path);
                }
            }
        }
        path += "."; // "." for going back.
    }

    vector<int> dirs = {-1, 0, 1, 0, -1};
    vector<string> pathDir = {"U", "L", "D", "R"};
};

/**
694. Number of Distinct Islands

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 
4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated 
(and not rotated or reflected) to equal the other.

Return the number of distinct islands.
 */
