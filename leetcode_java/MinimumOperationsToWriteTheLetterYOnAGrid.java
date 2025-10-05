// From: https://algo.monster/liteproblems/3071
// Time: O(n*n), Space: O(1).
class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        int gridSize = grid.length;
      
        // Count frequency of values (0, 1, or 2) in Y-shape and non-Y cells
        int[] yPatternCounts = new int[3];
        int[] nonYPatternCounts = new int[3];
      
        // Iterate through entire grid
        for (int row = 0; row < gridSize; ++row) {
            for (int col = 0; col < gridSize; ++col) {
                // Check if current cell belongs to the Y pattern
                boolean isOnLeftDiagonal = (row == col) && (row <= gridSize / 2);
                boolean isOnRightDiagonal = (row + col == gridSize - 1) && (row <= gridSize / 2);
                boolean isOnVerticalStem = (col == gridSize / 2) && (row >= gridSize / 2);
              
                if (isOnLeftDiagonal || isOnRightDiagonal || isOnVerticalStem) {
                    // Cell is part of Y pattern
                    ++yPatternCounts[grid[row][col]];
                } else {
                    // Cell is not part of Y pattern
                    ++nonYPatternCounts[grid[row][col]];
                }
            }
        }
      
        // Find minimum operations needed
        int totalCells = gridSize * gridSize;
        int minimumOperations = totalCells;
      
        // Try all combinations of values for Y pattern (i) and non-Y cells (j)
        for (int yValue = 0; yValue < 3; ++yValue) {
            for (int nonYValue = 0; nonYValue < 3; ++nonYValue) {
                // Y pattern and non-Y cells must have different values
                if (yValue != nonYValue) {
                    // Operations needed = total cells - cells already having correct values
                    int operationsNeeded = totalCells - yPatternCounts[yValue] - nonYPatternCounts[nonYValue];
                    minimumOperations = Math.min(minimumOperations, operationsNeeded);
                }
            }
        }
   
        return minimumOperations;
    }
}

/**
3071. Minimum Operations to Write the Letter Y on a Grid

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
