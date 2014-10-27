//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

// This works too and is more clear. 10-26-2014
class Solution2 {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        
        vector<vector<int> > v(M, vector<int>(N, 0));
        
        for (int j = 0; j < N; ++ j) {
            if (obstacleGrid[0][j] == 1) {
                //v[0][j] = 0; // already 0 in initialization of vector.
                //for (; j < N; ++ j) v[0][j] = 0;                
                break;
            }
            v[0][j] = 1;
        }
        
        for (int i = 1; i < M; ++ i) {
            if (obstacleGrid[i][0] == 1) v[i][0] = 0;
            else v[i][0] = v[i-1][0];
            
            for (int j = 1; j < N; ++ j) {
                if (obstacleGrid[i][j] == 1) v[i][j] = 0;
                else v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }
        return v[M-1][N-1];
    }
};


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
