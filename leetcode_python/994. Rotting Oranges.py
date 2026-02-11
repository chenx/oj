class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        def getRottingOrangeCount(grid, curRotten):
            count = 0
            for i in range(rows):
                for j in range(cols):
                    if grid[i][j] == curRotten:
                        for k in range(4):
                            x, y = i + options[k], j + options[k+1]
                            if x >= 0 and x < rows and y >= 0 and y < cols and grid[x][y] == 1:
                                grid[x][y] = curRotten + 1
                                count += 1
            return count

        rows, cols = len(grid), len(grid[0])
        options = [-1, 0, 1, 0, -1]

        minutes = 0
        while True:
            if getRottingOrangeCount(grid, minutes + 2) == 0:
                break
            minutes += 1

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1: # there are still fresh oranges.
                    return -1

        return minutes

/**
994. Rotting Oranges
Solved
Medium
Topics
conpanies iconCompanies

You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 */
