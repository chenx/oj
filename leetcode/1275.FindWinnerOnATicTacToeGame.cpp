//
// Time complexity: O(m)
// Space complexity: O(m)
//
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3, 0), cols(3, 0);
        int diag = 0, anti = 0, player = 1;

        for (auto move : moves) {
            int row = move[0], col = move[1];
            rows[row] += player;
            cols[col] += player;
            if (row == col) diag += player;
            if (row + col == 2) anti += player;

            if (abs(rows[row]) == 3 || abs(cols[col]) == 3 || abs(diag) == 3 || abs(anti) == 3) {
                return player == 1 ? "A" : "B";
            }
            player = -player;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};


/**
1275. Find Winner on a Tic Tac Toe Game
Easy

Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

    Players take turns placing characters into empty squares ' '.
    The first player A always places 'X' characters, while the second player B always places 'O' characters.
    'X' and 'O' characters are always placed into empty squares, never on filled ones.
    The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.

Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

 

Example 1:

Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
 */
