//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// Be careful that when initialize a[i][0] and a[0][j], 
// obstacleGrid should also be considered.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(); //
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        
        int i, j;
        int a[m][n];
        // int * a[m];
        // for (i = 0; i < m; i ++) { a[i] = new int[n]; }

        for (j = 0; j < n; j ++) { 
            if (obstacleGrid[0][j] == 0) a[0][j] = 1;
            else {
                for (; j < n; j ++) a[0][j] = 0;
                break;
            }
        }
        for (i = 0; i < m; i ++) { 
            if (obstacleGrid[i][0] == 0) a[i][0] = 1;
            else {
                for (; i < m; i ++) a[i][0] = 0;
                break;
            }
        }
        
        for (i = 1; i < m; i ++) {
            for (j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] == 1) a[i][j] = 0;
                else a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[m-1][n-1];
    }
};
