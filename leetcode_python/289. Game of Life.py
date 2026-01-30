class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def getNeighborSum(board, i, j):
            sum = 0
            options = [
                [-1, -1], [0, -1], [1, -1],
                [-1,  0],          [1,  0],
                [-1,  1], [0,  1], [1,  1],
            ]
            for option in options:
                x, y = i + option[0], j + option[1]
                if x >= 0 and x < rows and y >= 0 and y < cols: # Note: rows and cols are available.
                    sum += (board[x][y] & 0x1)
            return sum

        rows, cols = len(board), len(board[0])
        for i in range(rows):
            for j in range(cols):
                sum = getNeighborSum(board, i, j)
                if board[i][j] == 1:
                    if sum == 2 or sum == 3:
                        board[i][j] += 2
                else:
                    if sum == 3:
                        board[i][j] += 2
        
        for i in range(rows):
            for j in range(cols):
                board[i][j] >>= 1

/**
289. Game of Life
Solved
Medium
Topics
conpanies iconCompanies

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton 
devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) 
or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the 
current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.
 */
