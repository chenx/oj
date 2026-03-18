class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        def dfs(i, j):
            nonlocal path
            grid[i][j] = 2
            for k in range(len(directions)):
                x, y = i + directions[k][0], j + directions[k][1]
                if x >= 0 and x < rows and y >= 0 and y < cols and grid[x][y] == 1:
                    path += options[k]
                    dfs(x, y)
            path += '.'
        
        directions = [[-1,0], [0,1], [1,0], [0,-1]]
        options = ['U', 'D', 'L', 'R']    

        islands = set()
        rows, cols = len(grid), len(grid[0])
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    path = ''
                    dfs(i, j)
                    islands.add(path)
        
        return len(islands)


/**
694. Number of Distinct Islands
Solved
Medium
Topics
conpanies iconCompanies

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally 
(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or 
reflected) to equal the other.

Return the number of distinct islands.
 */
