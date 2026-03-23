class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        # count number of cells in Y and not in Y for grid value 0, 1, 2
        # for each of the combinations of Y/non-Y cells, get the options needed
        # and choose the min options.
        n = len(grid)

        yCells, nonYCells = [0] * 3, [0] * 3
        for i in range(n):
            for j in range(n):
                if ((i == j or i + j == n-1) and i <= n//2) or (j == n//2 and i >= n//2):
                    yCells[grid[i][j]] += 1
                else:
                    nonYCells[grid[i][j]] += 1
        
        total = n*n
        minOperations = total
        operations = 0
        for i in range(3):
            for j in range(3):
                if i != j:
                    operations = total - yCells[i] - nonYCells[j]
                    minOperations = min(minOperations, operations)
        return minOperations


/**
3071. Minimum Operations to Write the Letter Y on a Grid
Solved
Medium
Topics
conpanies iconCompanies

You are given a 0-indexed n x n grid where n is odd, and grid[r][c] is 0, 1, or 2.

We say that a cell belongs to the Letter Y if it belongs to one of the following:

    The diagonal starting at the top-left cell and ending at the center cell of the grid.
    The diagonal starting at the top-right cell and ending at the center cell of the grid.
    The vertical line starting at the center cell and ending at the bottom border of the grid.

The Letter Y is written on the grid if and only if:

    All values at cells belonging to the Y are equal.
    All values at cells not belonging to the Y are equal.
    The values at cells belonging to the Y are different from the values at cells not belonging to the Y.

Return the minimum number of operations needed to write the letter Y on the grid given that in one operation 
you can change the value at any cell to 0, 1, or 2.
 */
