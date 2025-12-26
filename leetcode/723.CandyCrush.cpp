// From: https://leetcode.com/problems/candy-crush/editorial/
// Let m×n be the size of the grid board.
// Time: O(m^2⋅n^2) - O(mn) for each of find_and_crush() and drop().
// Space: O(1)
class Solution {
private:
    int m, n;

    bool findAndCrushComplete(vector<vector<int>>& board) {
        bool complete = true;

        // Check vertically adjacent candies.
        for (int r = 1; r < m - 1; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (abs(board[r][c]) == abs(board[r - 1][c]) && abs(board[r][c]) == abs(board[r + 1][c])) {
                    board[r][c] = - abs(board[r][c]);
                    board[r - 1][c] = - abs(board[r - 1][c]);
                    board[r + 1][c] = - abs(board[r + 1][c]);
                    complete = false;
                }
            }
        }

        // Check horizontally adjacent candies
        for (int r = 0; r < m; r++) {
            for (int c = 1; c < n - 1; c++) {
                if (board[r][c] == 0) {
                    continue;
                }
                if (abs(board[r][c]) == abs(board[r][c - 1]) && abs(board[r][c]) == abs(board[r][c + 1])) {
                    board[r][c] = - abs(board[r][c]);
                    board[r][c - 1] = - abs(board[r][c - 1]);
                    board[r][c + 1] = - abs(board[r][c + 1]);
                    complete = false;
                }
            }
        }

        // Set the value of each candy to be crushed as 0
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] < 0) {
                    board[r][c] = 0;
                }
            }
        }

        return complete;
    }

    void drop(vector<vector<int>>& board) {
        // Iterate over each column
        for (int c = 0; c < n; c++) {
            int lowestZero = -1;
            for (int r = m - 1; r >= 0; r--) {
                if (board[r][c] == 0) {
                    lowestZero = max(lowestZero, r);
                } else if (lowestZero >= 0) {
                    swap(board[r][c], board[lowestZero][c]);
                    lowestZero--;
                }
            }
        }
    }

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        // Continue with the three steps until we can no longer find any crushable candies.
        while (!findAndCrushComplete(board)) {
            drop(board);
        }

        return board;
    }
};


/**
723. Candy Crush
Medium

This question is about implementing a basic elimination algorithm for Candy Crush.

Given an m x n integer array board representing the grid of candy where board[i][j] represents the type of candy. 
A value of board[i][j] == 0 represents that the cell is empty.

The given board represents the state of the game following the player's move. Now, you need to restore the board 
to a stable state by crushing candies according to the following rules:

    If three or more candies of the same type are adjacent vertically or horizontally, crush them all at the same 
        time - these positions become empty.
    After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then 
        these candies will drop until they hit a candy or bottom at the same time. No new candies will drop outside 
        the top boundary.
    After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
    If there does not exist more candies that can be crushed (i.e., the board is stable), then return the current board.

You need to perform the above rules until the board becomes stable, then return the stable board.
 */
