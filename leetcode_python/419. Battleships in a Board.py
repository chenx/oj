class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != 'X':
                return
            
            board[i][j] = '.'
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)


        m, n = len(board), len(board[0])

        count = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'X':
                    count += 1
                    dfs(i, j)
        
        return count


/**
419. Battleships in a Board
Solved
Medium
Topics
conpanies iconCompanies

Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of 
the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only 
be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any 
size. At least one horizontal or vertical cell separates between two battleships (i.e., there are 
no adjacent battleships).
 */
