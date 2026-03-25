class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def mark(i, j):
            if i < 0 or i >= rows or j < 0 or j >= cols or board[i][j] != 'O':
                return
            board[i][j] = 'K'
            mark(i + 1, j)
            mark(i - 1, j)
            mark(i, j + 1)
            mark(i, j - 1)

        rows, cols = len(board), len(board[0])
        for row in range(rows):
            mark(row, 0)
            mark(row, cols - 1)
        for col in range(cols):
            mark(0, col)
            mark(rows-1, col)

        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'K':
                    board[i][j] = 'O'
        

/**
130. Surrounded Regions
Solved
Medium
Topics
conpanies iconCompanies

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. 
        Such regions are completely enclosed by 'X' cells.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. 
You do not need to return anything.
 */
