# Time: O(n^2)
# Space: O(n^2) - size of islandsSizeMap, and call stack size.
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        def dfs(i, j, islandId):
            if i < 0 or i >= n or j < 0 or j >= n or grid[i][j] != 1:
                return 0
            
            grid[i][j] = islandId
            return 1 + dfs(i + 1, j, islandId) + \
                       dfs(i - 1, j, islandId) + \
                       dfs(i, j + 1, islandId) + \
                       dfs(i, j - 1, islandId)


        n = len(grid)
        islandIdSizeMap : dict[int, int] = {} # <id, size>
        islandId = 2

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    islandIdSizeMap[islandId] = dfs(i, j, islandId)
                    islandId += 1

        total = 0
        for _, size in islandIdSizeMap.items():
            total += size
        if total >= n * n - 1:
            return n * n

        maxSize = 0
        # for each water cell, check 4 neighbor cells
        for i in range(n):
            for j in range(n):
                islands = set()
                if grid[i][j] == 0:
                    if i > 0 and grid[i-1][j] > 0:
                        islands.add(grid[i-1][j])
                    if i < n-1 and grid[i+1][j] > 0:
                        islands.add(grid[i+1][j])
                    if j > 0 and grid[i][j-1] > 0:
                        islands.add(grid[i][j-1])
                    if j < n-1 and grid[i][j+1] > 0:
                        islands.add(grid[i][j+1])
                    
                    size = 1 # current cell
                    for islandId in islands:
                        size += islandIdSizeMap[islandId]
                    maxSize = max(maxSize, size)
        return maxSize


/**
827. Making A Large Island
Solved
Hard
Topics
conpanies iconCompanies

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
