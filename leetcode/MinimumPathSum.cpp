//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/25/2012
// @Last modified: 12/25/2012
//

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // assume grid has more than 1 row and 1 col.
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int> > sum(rows);
        vector<int> row(cols);
        
        row[0] = grid[0][0];
        for (int j = 1; j < cols; j ++) {
            row[j] = row[j-1] + grid[0][j];
        }
        sum[0] = row;

        for (int i = 1; i < grid.size(); i ++) {
            vector<int> row(cols);
            row[0] = grid[i][0] + sum[i-1][0];
            for (int j = 1; j < grid[0].size(); j ++) {
                row[j] = min(row[j-1], sum[i-1][j]) + grid[i][j];
            }
            sum[i] = row;
        }
        
        return sum[rows-1][cols-1];
    }
};


//
// This works too.
//
class Solution2 {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int j = 1; j < cols; ++ j) {
            grid[0][j] += grid[0][j-1];
        }
        
        for (int i = 1; i < rows; ++ i) {
            grid[i][0] += grid[i-1][0];
        }
        
        for (int i = 1; i < rows; ++ i) {
            for (int j = 1; j < cols; ++ j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[rows-1][cols-1];
    }
};