# Let N be the number of cells in the grid.
# Time, Space: O(N)
from collections import deque
class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 0 or grid[0][0] == 1:
            return -1
        if n == 1 and grid[0][0] == 0:
            return 1

        directions = [
            [-1,-1], [0,-1], [1,-1],
            [-1,0],          [1,0],
            [-1,1],  [0,1],  [1,1]
        ]

        q = deque([(0, 0, 1)])
        used = set([(0,0)])
        while q:
            (i, j, step) = q.popleft()

            for dir in directions:
                x, y = i + dir[0], j + dir[1]
                if x >= 0 and x < n and y >= 0 and y < n and grid[x][y] == 0:
                    if (x, y) not in used:
                        if (x, y) == (n-1, n-1):
                            return step + 1
                        used.add((x, y))
                        q.append((x, y, step + 1))
        return -1



/**
1091. Shortest Path in Binary Matrix
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 
If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right 
cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different 
        and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.
 */
