class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValidRow(board, row):
            count : dict[str, int] = {}
            for col in range(9):
                if board[row][col] == '.':
                    continue
                index = int(board[row][col])
                count[ index ] = count.get(index, 0) + 1
                if (count[ index ] > 1): return False
            return True

        def isValidCol(board, col):
            count : dict[str, int] = {}
            for row in range(9):
                if board[row][col] == '.':
                    continue
                index = int(board[row][col])
                count[ index ] = count.get(index, 0) + 1
                if (count[ index ] > 1): return False
            return True

        def isValidGrid(board, row, col):
            count : dict[str, int] = {}
            for i in range(3):
                for j in range(3):
                    if board[row + i][col + j] == '.':
                        continue
                    index = int(board[row + i][col + j])
                    count[ index ] = count.get(index, 0) + 1
                    if (count[ index ] > 1): return False
            return True

        rows, cols = len(board), len(board[0])

        for row in range(rows):
            if not isValidRow(board, row): return False

        for col in range(cols):
            if not isValidCol(board, col): return False

        for row in range(0, rows, 3):
            for col in range(0, cols, 3):
                if not isValidGrid(board, row, col): return False

        return True
 

/**
36. Valid Sudoku
Solved
Medium
Topics
conpanies iconCompanies

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
 */
