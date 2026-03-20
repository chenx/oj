# Time: O(n!)
# Space: O(n^2)
class Solution2:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def has_config(i, row):
            for i in range(row):
                if board[i] == board[row] or abs(board[i] - board[row]) == row  - i:
                    return True
            return False

        def dfs(row):
            if row == n:
                config = [['.'] * n for _ in range(n)]  # O(n^2)
                for i in range(n):
                    config[i][board[i]] = 'Q'
                    config[i] = ''.join(config[i])
                result.append(config)
                return 
            
            for i in range(n):
                board[row] = i
                if not has_config(i, row):
                    dfs(row + 1)


        board = [0] * n
        result = []
        dfs(0)
        return result


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def hasConflict(board, pos):
            for i in range(0, pos):
                if board[i] == board[pos] or abs(board[i] - board[pos]) == abs(i - pos):
                    return True
            return False

        def dfs(board, row):
            if row == n:
                boardConfig = [['.' for _ in range(n)] for _ in range(n)]
                for i in range(n):
                    boardConfig[i][board[i]] = 'Q'
                    boardConfig[i] = ''.join(boardConfig[i]) # convert 2D array to 1D.
                result.append(boardConfig)
                return

            # choose value of row
            for i in range(n):
                board[row] = i
                if not hasConflict(board, row):
                    dfs(board, row + 1)

        result = []
        board = [0 for _ in range(n)]
        dfs(board, 0)
        return result


/**
51. N-Queens
Solved
Hard
Topics
conpanies iconCompanies

The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. 
You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space, respectively.
 */
