class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        len1, len2 = len(matrix), len(matrix[0])
        DP = [[0 for _ in range(len2)] for _ in range(len1)]

        maxSide = 0
        for i in range(len1):
            DP[i][0] = int(matrix[i][0])
            if DP[i][0] == 1: maxSide = 1
        for j in range(len2):
            DP[0][j] = int(matrix[0][j])
            if DP[0][j] == 1: maxSide = 1

        for i in range(1,len1):
            for j in range(1,len2):
                if matrix[i][j] == '0':
                    DP[i][j] = 0
                else:
                    DP[i][j] = 1 + min(DP[i-1][j-1], DP[i-1][j], DP[i][j-1])
                    maxSide = max(maxSide, DP[i][j])
        # print(DP)
        return maxSide ** 2

/**
221. Maximal Square
Solved
Medium
Topics
conpanies iconCompanies

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
 */
