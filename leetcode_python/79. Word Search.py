class Solution2:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j, wordPos):
            if wordPos == len(word):
                return True
            if i < 0 or i >= rows or j < 0 or j >= cols or board[i][j] != word[wordPos]:
                return False
            
            ch = board[i][j]
            board[i][j] = '.'

            if dfs(i + 1, j, wordPos + 1): return True
            if dfs(i - 1, j, wordPos + 1): return True
            if dfs(i, j + 1, wordPos + 1): return True
            if dfs(i, j - 1, wordPos + 1): return True

            board[i][j] = ch
            return False

        if len(board) == 0 or len(board[0]) == 0 or len(word) == 0:
            return False
        rows, cols = len(board), len(board[0])

        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0]:
                    if dfs(i, j, 0):
                        return True
        return False


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(board, i, j, word, pos):
            if pos == len(word):
                return True
            
            c = board[i][j]
            board[i][j] = '.'

            directions = [-1, 0, 1, 0, -1]
            for k in range(4):
                x, y = i + directions[k], j + directions[k+1]
                if x >= 0 and x < len(board) and y >= 0 and y < len(board[0]):
                    if board[x][y] == word[pos]:
                        if dfs(board, x, y, word, pos + 1):
                            return True
            
            board[i][j] = c
            return False


        if len(board) == 0 or len(board[0]) == 0 or len(word) == 0:
            return False

        rows, cols = len(board), len(board[0])
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0]:
                    if dfs(board, i, j, word, 1):
                        return True
        
        return False


/**
79. Word Search
Solved
Medium
Topics
conpanies iconCompanies

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once.
 */
