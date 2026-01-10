// Works.
// Time: O(mn)
// Space: O(mn)
class Solution2 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        static int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<vector<int>> q;
        set<vector<int>> visited;

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    visited.insert({i, j});
                }
            }
        }

        while (! q.empty()) {
            int i = q.front()[0], j = q.front()[1], dist = q.front()[2];
            q.pop();

            for (int k = 0; k < 4; ++ k) {
                int x = i + directions[k][0], y = j + directions[k][1];
                if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) {
                    if (! visited.contains({x, y})) {
                        if (mat[x][y] != 0) {
                            ans[x][y] = 1 + dist;

                            visited.insert({x, y});
                            q.push({x, y, 1 + dist});
                        }
                    }
                }
            }
        }

        return ans;
    }
};


class Solution {
    vector<vector<int>> ans;//(m, vector<int>(n, 0));
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        ans = vector<vector<int>>(m, vector<int>(n, 0));
        // vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (mat[i][j] == 1) {
                    ans[i][j] = bfs(mat, i, j);
                }
            }
        }
        return ans;
    }

    // Better than DFS, but still time out for large input.
    int bfs(vector<vector<int>>& mat, int i, int j) {
        static int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        queue<vector<int>> q;
        q.push({i, j, 0});

        set<vector<int>> visited;
        visited.insert({i, j});

        while (! q.empty()) {
            int i = q.front()[0], j = q.front()[1], dist = q.front()[2];
            q.pop();

            for (int k = 0; k < 4; ++ k) {
                int x = i + directions[k][0], y = j + directions[k][1];
                if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) {
                    if (! visited.contains({x, y})) {
                        if (mat[x][y] == 0) return 1 + dist;

                        visited.insert({x, y});
                        q.push({x, y, 1 + dist});
                    }
                }
            }
        }
        return 0;
    }

    // Time out for large input.
    int dfs(vector<vector<int>>& mat, int i, int j) {
        if (ans[i][j] != 0) return ans[i][j];
        if (mat[i][j] == 0) return 0;

        int backup = mat[i][j];
        mat[i][j] = 2; // mark as visited.

        static int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int minDist = -1;
        for (int k = 0; k < 4; ++ k) {
            int x = i + directions[k][0], y = j + directions[k][1];
            if (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size() && mat[x][y] != 2) {
                if (minDist == -1) minDist = dfs(mat, x, y);
                else minDist = min(minDist, dfs(mat, x, y));
            }
        }
        mat[i][j] = backup;

        return minDist == -1 ? 0 : 1 + minDist;
    }
};

/**
542. 01 Matrix
Medium

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
 */
