class Solution {
    int UNGUARDED = 0;
    int GUARDED = 1;
    int WALL = 2;
    int GUARD = 3;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = GUARDED;
        for (int row = i-1; row >= 0; -- row) {
            if (grid[row][j] == WALL || grid[row][j] == GUARD) break;
            grid[row][j] = GUARDED;
        }
        for (int row = i+1; row < grid.size(); ++ row) {
            if (grid[row][j] == WALL || grid[row][j] == GUARD) break;
            grid[row][j] = GUARDED;
        }
        for (int col = j-1; col >= 0; -- col) {
            if (grid[i][col] == WALL || grid[i][col] == GUARD) break;
            grid[i][col] = GUARDED;
        }
        for (int col = j+1; col < grid[0].size(); ++ col) {
            if (grid[i][col] == WALL || grid[i][col] == GUARD) break;
            grid[i][col] = GUARDED;
        }
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        for (auto e : walls) grid[e[0]][e[1]] = WALL;
        for (auto e : guards) grid[e[0]][e[1]] = GUARD;
        for (auto e : guards) dfs(grid, e[0], e[1]);
        
        int count = 0;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == UNGUARDED) ++ count;
            }
        }
        return count;
    }
};


/**
2257. Count Unguarded Cells in the Grid
Medium

You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls 
where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless 
obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.
 */
