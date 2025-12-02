// See: https://leetcode.com/problems/shortest-bridge/editorial/
// BFS
// Time complexity: O(n2)
// Space complexity: O(n2)
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int startX = 0, startY = 0;
        bool found = false;

        for (int i = 0; i < m && ! found; ++ i) {
            for (int j = 0; j < n && ! found; ++ j) {
                if (grid[i][j] == 1) {
                    startX = i, startY = j;
                    grid[i][j] = 2;
                    found = true;
                }
            }
        }

        queue<vector<int>> q1, q2;
        q1.push({startX, startY});
        q2.push({startX, startY, 0});
        vector<vector<int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

        while(! q1.empty()) { // add all cells in island1 to q2.
            int i = q1.front()[0], j = q1.front()[1];
            q1.pop();

            for (auto dir : directions) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 1) {
                        grid[x][y] = 2; // mark as visited.
                        q1.push({x, y});
                        q2.push({x, y, 0});
                    }
                }
            }
        }

        while (! q2.empty()) {
            int i = q2.front()[0], j = q2.front()[1], dist = q2.front()[2];
            q2.pop();

            for (auto dir : directions) {
                int x = i + dir[0], y = j + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 1) {
                        return dist;
                    } else if (grid[x][y] == 0) { // water
                        grid[x][y] = -1; // mark as visited.
                        q2.push({x, y, 1 + dist});
                    }
                }
            }
        }

        return -1;
    }
};



/**
934. Shortest Bridge
Medium

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1

Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 */
