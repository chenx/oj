// Works. Tested. Union Find.
// From: https://leetcode.com/discuss/78856/c-union-find-solution-with-path-compression
/*
// Note, use which below do not matter. 
// Final result is the same, although roots vector is different.

// Use roots[posOld] = posNew;
1 1 2 3 2 1 
roots: 0 -1 -1 -1 -1 -1 -1 -1 -1 
roots: 1 1 -1 -1 -1 -1 -1 -1 -1 
roots: 1 1 -1 -1 -1 5 -1 -1 -1 
roots: 1 1 -1 -1 -1 5 -1 7 -1 
roots: 1 1 -1 -1 -1 8 -1 8 8 
roots: 1 4 -1 -1 4 8 -1 8 4 
1 1 2 3 2 1 
ok

// Use roots[posNew] = posOld;
1 1 2 3 2 1 
roots: 0 -1 -1 -1 -1 -1 -1 -1 -1 
roots: 0 0 -1 -1 -1 -1 -1 -1 -1 
roots: 0 0 -1 -1 -1 5 -1 -1 -1 
roots: 0 0 -1 -1 -1 5 -1 7 -1 
roots: 0 0 -1 -1 -1 7 -1 7 5 
roots: 0 0 -1 -1 7 7 -1 0 5 
1 1 2 3 2 1 
ok
*/

// Works.
class Solution2 {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ans;
        vector<int> dirs = {-1, 0, 1, 0 , -1};
        int islands = 0;
        vector<int> roots(m*n, -1);

        for (vector<int>& pos : positions) {
            int idx_pos = pos[0] * n + pos[1];
            if (roots[idx_pos] != -1) {  // already visited this cell.
                ans.push_back(islands);
                continue;
            }

            roots[idx_pos] = idx_pos;
            ++ islands;

            for (int k = 0; k < 4; ++ k) {
                int x = pos[0] + dirs[k], y = pos[1] + dirs[k + 1];
                int idx_new = x * n + y;
                if (x >= 0 && x < m && y >= 0 && y < n && roots[idx_new] != -1)  {
                    int root_pos = findRoot(roots, idx_pos), 
                        root_new = findRoot(roots, idx_new);
                    if (root_pos != root_new) {
                        roots[root_pos] = root_new;
                        -- islands;
                    }
                }
            }
            ans.push_back(islands);
        }
        return ans;
    }

    int findRoot(vector<int>& roots, int idx) {
        while (idx != roots[idx]) {
            roots[idx] = roots[roots[idx]];
            idx = roots[idx];
        }
        return idx;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        roots = vector<int>(m * n, -1);
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int island = 0;
        for (auto pos : positions) {
            int x = pos.first, y = pos.second, idx_p = x * n + y;
            if (roots[idx_p] != -1) {
                ans.push_back(islands);
                continue;
            }

            roots[idx_p] = idx_p;
            ++island;
            for (auto dir : dirs) {
                int row = x + dir.first, col = y + dir.second, idx_new = row * n + col;
                if (row >= 0 && row < m && col >= 0 && col < n && roots[idx_new] != -1) {
                    int rootNew = findRoot(idx_new), rootPos = findRoot(idx_p);
                    if (rootPos != rootNew) {
                        roots[rootPos] = rootNew;
                        //roots[rootNew] = rootPos;  // this works too.
                        --island;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }
    
private:

    vector<int> roots;
    int findRoot(int idx) {
        while(idx != roots[idx]) {
            roots[idx] = roots[roots[idx]]; 
            idx = roots[idx];
        }
        return idx;
    }
};


/**
Number of Islands II
Difficulty: Hard

A 2d grid map of m rows and n columns is initially filled with water. 
We may perform an addLand operation which turns the water at position 
(row, col) into a land. Given a list of positions to operate, count 
the number of islands after each addLand operation. An island is 
surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid 
are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents 
water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of 
the positions?
 */
