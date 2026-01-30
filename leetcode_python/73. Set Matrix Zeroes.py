class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.

        if matrix[i][j] == 0, set first elem in row and col to 0
        state of first row/col are stored separately.
        """
        if len(matrix) == 0: 
            return

        rows, cols = len(matrix), len(matrix[0])

        row0, col0 = False, False
        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0

                    if i == 0: row0 = True
                    if j == 0: col0 = True
        
        for row in range(1, rows):
            if matrix[row][0] == 0: # set entire row to 0
                for col in range(0, cols):
                    matrix[row][col] = 0
        
        for col in range(1, cols):
            if matrix[0][col] == 0: # set entire col to 0
                for row in range(0, rows):
                    matrix[row][col] = 0
        
        if row0: # set first row to 0
            for col in range(0, cols):
                matrix[0][col] = 0
        if col0: # set first col to 0
            for row in range(0, rows):
                matrix[row][0] = 0
        

/**
73. Set Matrix Zeroes
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
 */
