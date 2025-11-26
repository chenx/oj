// From: https://leetcode.com/problems/island-perimeter/editorial/
// Time complexity : O(mn)
// Space: O(1)
class Solution2 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int result = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    result += 4;
                    
                    if (r > 0 && grid[r-1][c] == 1) {
                        result -= 2;
                    }
                    
                    if (c > 0 && grid[r][c-1] == 1) {
                        result -= 2;
                    }
                }
            }
        }
        
        return result;
    }
};

// DFS
// Time complexity : O(mn)
// Space: O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, perimeter);
                }
            }
        }
        return perimeter;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& perimeter) {
        grid[i][j] = 2; // mark as visited.

        static vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        int edges = 0;
        for (int k = 0; k < 4; ++ k) {
            int x = i + directions[k][0], y = j + directions[k][1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (grid[x][y] == 1) {
                    dfs(grid, x, y, perimeter);
                } else if (grid[x][y] == 0) {
                    ++ edges;
                }
            } else {
                ++ edges;
            }
        }
        perimeter += edges;
    }
};


/**
463. Island Perimeter
Easy

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One 
cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the 
perimeter of the island.

 

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:

Input: grid = [[1]]
Output: 4

Example 3:

Input: grid = [[1,0]]
Output: 4
 */
