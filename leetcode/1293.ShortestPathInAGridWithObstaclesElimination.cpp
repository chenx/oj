// See: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/editorial/
// BFS
// Time Complexity: O(N⋅K). N is the number of cells in the grid, and K is the quota to eliminate obstacles.
// Space Complexity: O(N⋅K)
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        if (m == 1 && n == 1) return 0; // start == end

        queue<vector<int>> q; // <i, j, distance, available eliminations k>
        q.push({0, 0, 0, k});

        set<vector<int>> visited; // <i, j, available eliminations k>
        visited.insert({0, 0, k});

        int directions[5] = {1, 0, -1, 0, 1};

        while (! q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int dist = q.front()[2];
            int elim = q.front()[3];
            q.pop();

            for (int k = 0; k < 4; ++ k) {
                int x = i + directions[k], y = j + directions[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int newElim = elim;
                    if (grid[x][y] == 1) {
                        if (elim == 0) continue;
                        -- newElim;
                    }

                    if (! visited.contains({x, y, newElim})) {
                        if (x == m - 1 && y == n - 1) {
                            return dist + 1;
                        }

                        visited.insert({x, y, newElim});
                        q.push({x, y, dist + 1, newElim});
                    }
                }
            }
        }
        return -1;
    }
};


/**
1293. Shortest Path in a Grid with Obstacles Elimination
Hard

You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right 
corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible 
to find such walk return -1.
 */
