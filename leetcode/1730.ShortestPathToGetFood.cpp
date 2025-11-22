// BFS.
// Only trick: break out of the 2D loop when getting start position.
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int i = 0, j = 0, m = grid.size(), n = grid[0].size();
        bool foundStart = false;
        for (i = 0; i < m; ++ i) {
            for (j = 0; j < n; ++ j) {
                if (grid[i][j] == '*') {
                    foundStart = true;
                    break;
                }
            }
            if (foundStart) break;
        }

        queue<vector<int>> q; // <i, j, distance>
        q.push({i, j, 0});

        set<vector<int>> visited;
        visited.insert({i, j});

        int directions[5] = {1, 0, -1, 0, 1};

        while (! q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int dist = q.front()[2];
            q.pop();

            for (int k = 0; k < 4; ++ k) {
                int x = i + directions[k], y = j + directions[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] != 'X' && ! visited.contains({x, y})) {
                        if (grid[x][y] == '#') {
                            return dist + 1;
                        }

                        visited.insert({x, y});
                        q.push({x, y, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};

/**
1730. Shortest Path to Get Food
Medium

You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at any food cell.

You are given an m x n character matrix, grid, of these different types of cells:

    '*' is your location. There is exactly one '*' cell.
    '#' is a food cell. There may be multiple food cells.
    'O' is free space, and you can travel through these cells.
    'X' is an obstacle, and you cannot travel through these cells.

You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the length of the shortest path for you to reach any food cell. If there is no path for you to reach food, return -1.
 */
