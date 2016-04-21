class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        m = grid.size(), n = grid[0].size();
        int ct = 0;
        
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (grid[i][j]) {
                    ++ ct;
                    flip(grid, i, j);
                }
                
        return ct;
    }
    
    void flip(vector<vector<bool>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || ! grid[i][j]) return;
        
        grid[i][j] = false;
        flip(grid, i+1, j);
        flip(grid, i-1, j);
        flip(grid, i, j+1);
        flip(grid, i, j-1);
    }
    
    int m, n;
};


/**
Number of Islands

Given a boolean 2D matrix, find the number of islands.
Have you met this question in a real interview?
Notice

0 is represented as the sea, 1 is represented as the island. 
If two 1 is adjacent, we consider them in the same island. 
We only consider up/down/left/right adjacent.

Example

Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]

return 3.

 */
