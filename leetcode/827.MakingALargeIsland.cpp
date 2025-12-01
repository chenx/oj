// Time and Space: O(mn)
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();

        map<int, int> islandSize; // <islandId, size>
        int islandId = 2;

        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j] == 1) {
                    islandSize[islandId] = dfs(grid, i, j, islandId);
                    ++ islandId;
                }
            }
        }

        if (islandSize.empty()) return 1;
        if (islandSize.size() == 1) {
            int total = m*n;
            return islandSize[2] == total ? total : islandSize[2] + 1;
        }

        int maxLand = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j] == 0) {
                    set<int> islands;
                    if (i < grid.size() - 1 && grid[i+1][j] > 1) {
                        islands.insert(grid[i+1][j]);
                    }
                    if (i > 0 && grid[i-1][j] > 1) {
                        islands.insert(grid[i-1][j]);
                    }
                    if (j < grid[0].size() - 1 && grid[i][j+1] > 1) {
                        islands.insert(grid[i][j+1]);
                    }
                    if (j > 0 && grid[i][j-1] > 1) {
                        islands.insert(grid[i][j-1]);
                    }
                
                    int land = 1;
                    for (int island : islands) {
                        land += islandSize[island];
                    }
                    maxLand = max(maxLand, land);
                }
            }
        }
        return maxLand;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int islandId) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 1) {
            return 0;
        } 
        grid[i][j] = islandId;

        return 1 + dfs(grid, i+1, j, islandId) + 
            dfs(grid, i-1, j, islandId) + 
            dfs(grid, i, j+1, islandId) + 
            dfs(grid, i, j-1, islandId);
    }
};


/**
827. Making A Large Island
Hard

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 */
