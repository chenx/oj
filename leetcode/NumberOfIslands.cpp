// Works too. Slightly modified from Solution.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int ct = 0;
        rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (grid[i][j] == '1') {
                    ++ ct;
                    flip(grid, i, j);
                }
            }
        }

        return ct;
    }

private:
    int rows, cols;
    vector<pair<int, int>> d = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
    
    void flip(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        
        for (int k = 0; k < d.size(); ++ k) {
            int dx = i + d[k].first, dy = j + d[k].second;
            if (dx >= 0 && dx < rows && dy >= 0 && dy < cols && grid[dx][dy] == '1') {
                flip(grid, dx, dy);
            }
        }
    }
};


// Works.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int ct = 0;
        rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (grid[i][j] == '1') {
                    ++ ct;
                    flip(grid, i, j);
                }
            }
        }

        return ct;
    }

private:
    int rows, cols;
    
    void flip(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        
        if (i > 0 && grid[i-1][j] == '1') flip(grid, i-1, j);
        if ((i < rows-1) && grid[i+1][j] == '1') flip(grid, i+1, j);
        if (j > 0 && grid[i][j-1] == '1') flip(grid, i, j-1);
        if ((j < cols-1) && grid[i][j+1] == '1') flip(grid, i, j+1);
    }
};

/**
Number of Islands
Difficulty: Medium

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3
 */
