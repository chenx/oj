class TicTacToe:

    def __init__(self, n: int):
        self.size = n
        self.rows = [0] * n
        self.cols = [0] * n
        self.diag = 0
        self.anti = 0

    def move(self, row: int, col: int, player: int) -> int:
        diff = 1 if player == 1 else -1
        self.rows[row] += diff
        self.cols[col] += diff
        self.diag += diff if row == col else 0
        self.anti += diff if row + col == self.size - 1 else 0

        if abs(self.rows[row]) == self.size or abs(self.cols[col]) == self.size or \
            abs(self.diag) == self.size or abs(self.anti) == self.size:
            return 1 if player == 1 else 2
        return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)

/**
348. Design Tic-Tac-Toe
Solved
Medium
Topics
conpanies iconCompanies
Hint

Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

    A move is guaranteed to be valid and is placed on an empty block.
    Once a winning condition is reached, no more moves are allowed.
    A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Implement the TicTacToe class:

    TicTacToe(int n) Initializes the object the size of the board n.
    int move(int row, int col, int player) Indicates that the player with id player plays at the cell 
    (row, col) of the board. The move is guaranteed to be a valid move, and the two players alternate 
    in making moves. Return
        0 if there is no winner after the move,
        1 if player 1 is the winner after the move, or
        2 if player 2 is the winner after the move.
 */
