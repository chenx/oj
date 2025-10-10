class Solution3 {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> yPattern(3, 0), notYPattern(3, 0);

        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if ((i == j && i <= n/2) || 
                    (i + j == n-1 && i <= n/2) ||
                    (j == n/2 && i >= n/2)
                   ) {
                    ++ yPattern[grid[i][j]];
                } else {
                    ++ notYPattern[grid[i][j]];
                }
            }
        }

        int total = n*n; // total number of operations
        int minTotal = INT_MAX;
        // try all 3x3 combinations of values in Y and not in Y.
        for (int i = 0; i < 3; ++ i) {
            for (int j = 0; j < 3; ++ j) {
                if (i != j) {
                    minTotal = min(minTotal, total - yPattern[i] - notYPattern[j]);
                }
            }
        }
        return minTotal;
    }
};

// Same as Solution, just cleaned up.
class Solution2 {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int yPattern[3] = {0}, nonYPattern[3] = {0};  

        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i == j && i <= n/2) { // left arm of Y
                    ++ yPattern[grid[i][j]];
                } else if (i + j == n-1 && i <= n/2) {
                    ++ yPattern[grid[i][j]];
                } else if (j == n/2 && i >= n/2) {
                    ++ yPattern[grid[i][j]];
                } else {
                    ++ nonYPattern[grid[i][j]];
                }
            }
        }

        int total = n*n, minOperations = INT_MAX;
        for (int i = 0; i < 3; ++ i) {
            for (int j = 0; j < 3; ++ j) {
                if (i != j) {
                    int operations = total - yPattern[i] - nonYPattern[j];
                    minOperations = min(minOperations, operations);
                }
            }
        }

        return minOperations;
    }
};

// From https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/
class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
    
        // Count frequency of values (0, 1, 2) in Y pattern and non-Y cells
        int yPatternCount[3] = {0};      // Frequency of each value in Y pattern
        int nonYPatternCount[3] = {0};   // Frequency of each value outside Y pattern
      
        // Iterate through the entire grid
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                // Check if current cell belongs to Y pattern
                // Y pattern consists of three parts:
              
                // Part 1: Main diagonal from top-left (first half)
                bool isMainDiagonal = (row == col) && (row <= n / 2);
              
                // Part 2: Anti-diagonal from top-right (first half)
                bool isAntiDiagonal = (row + col == n - 1) && (row <= n / 2);
              
                // Part 3: Vertical line from center to bottom
                bool isVerticalStem = (col == n / 2) && (row >= n / 2);
              
                // If cell is part of Y pattern
                if (isMainDiagonal || isAntiDiagonal || isVerticalStem) {
                    ++yPatternCount[grid[row][col]];
                } else {
                    // Cell is not part of Y pattern
                    ++nonYPatternCount[grid[row][col]];
                }
            }
        }
      
        // Find minimum operations by trying all combinations
        int minOperations = n * n;  // Initialize with maximum possible operations
      
        // Try all possible value assignments
        // i: value to assign to Y pattern cells
        // j: value to assign to non-Y pattern cells
        for (int i = 0; i < 3; ++ i) {
            for (int j = 0; j < 3; ++ j) {
                // Y pattern and non-Y pattern must have different values
                if (i != j) {
                    // Calculate operations needed for this combination
                    // Operations = total cells - cells already having correct value
                    int currentOperations = n * n - yPatternCount[i] - nonYPatternCount[j];
                    minOperations = min(minOperations, currentOperations);
                }
            }
        }
      
        return minOperations;
    }
};

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
