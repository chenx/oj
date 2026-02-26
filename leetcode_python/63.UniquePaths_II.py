# C(m+n-2, n-1) paths if no obstacle.
class Solution2:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        DP = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(0, m):
            if obstacleGrid[i][0] == 1:
                break
            DP[i][0] = 1
            
        for j in range(0, n):
            if obstacleGrid[0][j] == 1:
                break
            DP[0][j] = 1
            
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    DP[i][j] = 0
                else:
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1]
        
        return DP[m-1][n-1]


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])

        DP = [[0] * n for i in range(m)]  # m*n 2D array

        for i in range(m):
            if obstacleGrid[i][0] == 0: DP[i][0] = 1 
            else: break

        for j in range(n):
            if obstacleGrid[0][j] == 0: DP[0][j] = 1
            else: break

        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    DP[i][j] = 0
                else:
                    DP[i][j] = DP[i-1][j] + DP[i][j-1]

        return DP[m-1][n-1]

/**
63. Unique Paths II
Medium

You are given an m x n integer array grid. There is a robot initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot 
include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.
 */
