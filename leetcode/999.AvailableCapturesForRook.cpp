// Time: O(mn)
// Space: O(1)
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        bool foundRook = false;
        int i = 0, j = 0; // Find position of Rook.
        for (i = 0; i < m; ++ i) {
            for (j = 0; j < n; ++ j) {
                if (board[i][j] == 'R') {
                    foundRook = true;
                    break;
                }
            }
            if (foundRook) break;
        }

        int sum = 0;
        for (int row = i - 1; row >= 0; -- row) {
            if (board[row][j] == 'B') break;
            if (board[row][j] == 'p') { ++ sum; break; }
        }
        for (int row = i + 1; row < m; ++ row) {
            if (board[row][j] == 'B') break;
            if (board[row][j] == 'p') { ++ sum; break; }
        }
        for (int col = j - 1; col >= 0; -- col) {
            if (board[i][col] == 'B') break;
            if (board[i][col] == 'p') { ++ sum; break; }
        }
        for (int col = j + 1; col < n; ++ col) {
            if (board[i][col] == 'B') break;
            if (board[i][col] == 'p') { ++ sum; break; }
        }
        return sum;
    }
};


/**
999. Available Captures for Rook
Easy

You are given an 8 x 8 matrix representing a chessboard. There is exactly one white rook represented by 'R', 
some number of white bishops 'B', and some number of black pawns 'p'. Empty squares are represented by '.'.

A rook can move any number of squares horizontally or vertically (up, down, left, right) until it reaches 
another piece or the edge of the board. A rook is attacking a pawn if it can move to the pawn's square in one move.

Note: A rook cannot move through other pieces, such as bishops or pawns. This means a rook cannot attack a 
pawn if there is another piece blocking the path.

Return the number of pawns the white rook is attacking.
 */
