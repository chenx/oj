class Solution2:
    def totalNQueens(self, n: int) -> int:
        def has_conflict(i, row):
            for i in range(row):
                if board[i] == board[row] or abs(board[i] - board[row]) == row  - i:
                    return True
            return False

        def dfs(row):
            nonlocal count
            if row == n:
                count += 1
                return 
            
            for i in range(n):
                board[row] = i
                if not has_conflict(i, row):
                    dfs(row + 1)


        board = [0] * n
        count = 0
        dfs(0)
        return count


# Time: O(N!)
# Space: O(N) for board and recusion.
class Solution:
    def totalNQueens(self, n: int) -> int:
        def hasConflict(board, pos):
            for i in range(0, pos):
                if board[i] == board[pos] or abs(board[i] - board[pos]) == abs(i - pos):
                    return True
            return False

        def dfs(board, row):
            nonlocal count
            if row == n:
                count += 1
                return

            # choose value of row
            for i in range(n):
                board[row] = i
                if not hasConflict(board, row):
                    dfs(board, row + 1)

        board = [0 for _ in range(n)]
        count = 0
        dfs(board, 0)
        return count


/**
52. N-Queens II
Solved
Hard
Topics
conpanies iconCompanies

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 */
