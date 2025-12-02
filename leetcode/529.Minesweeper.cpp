// Simplified from Solution.
class Solution2 {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int i = click[0], j = click[1];
     
        if (board[i][j] == 'M') { // If clicked on a mine, game over
            board[i][j] = 'X';
        } else {
            revealBoard(board, m, n, i, j);
        }
     
        return board;
    }

    void revealBoard(vector<vector<char>>& board, int m, int n, int row, int col) {
        static vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1}, 
            {0, -1}, {0, 1}, 
            {1, -1}, {1, 0}, {1, 1}
        };

        int mineCount = 0; // Count adjacent mines.
        for (auto dir : directions) {
            int x = row + dir[0], y = col + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M') {
                ++ mineCount;
            }
        }

        if (mineCount > 0) {
            board[row][col] = mineCount + '0';  // Convert number to character
        } else {
            board[row][col] = 'B';  // Mark current cell as blank revealed
            
            for (auto dir : directions) {
                int x = row + dir[0], y = col + dir[1];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E') {
                    revealBoard(board, m, n, x, y);
                }
            }
        }
    };
};


// From: https://algo.monster/liteproblems/529
// Time: O(mn)
// Space: O(1)
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int rows = board.size();
        int cols = board[0].size();
        int clickRow = click[0];
        int clickCol = click[1];
     
        // Lambda function to recursively reveal the board using DFS
        function<void(int, int)> revealBoard = [&](int row, int col) {
            // Count adjacent mines
            int mineCount = 0;
         
            // Check all 8 adjacent cells for mines
            for (int adjRow = row - 1; adjRow <= row + 1; ++adjRow) {
                for (int adjCol = col - 1; adjCol <= col + 1; ++adjCol) {
                    // Check if adjacent cell is within bounds and contains a mine
                    if (adjRow >= 0 && adjRow < rows &&
                        adjCol >= 0 && adjCol < cols &&
                        board[adjRow][adjCol] == 'M') {
                        ++mineCount;
                    }
                }
            }
         
            // If there are adjacent mines, display the count
            if (mineCount > 0) {
                board[row][col] = mineCount + '0';  // Convert number to character
            }
            // If no adjacent mines, mark as blank and recursively reveal neighbors
            else {
                board[row][col] = 'B';  // Mark current cell as blank revealed
             
                // Recursively reveal all adjacent unrevealed empty cells
                for (int adjRow = row - 1; adjRow <= row + 1; ++adjRow) {
                    for (int adjCol = col - 1; adjCol <= col + 1; ++adjCol) {
                        // Check if adjacent cell is within bounds and unrevealed
                        if (adjRow >= 0 && adjRow < rows &&
                            adjCol >= 0 && adjCol < cols &&
                            board[adjRow][adjCol] == 'E') {
                            revealBoard(adjRow, adjCol);
                        }
                    }
                }
            }
        };
     
        // Handle the clicked cell
        if (board[clickRow][clickCol] == 'M') {
            // If clicked on a mine, game over - mark it as exploded mine
            board[clickRow][clickCol] = 'X';
        } else {
            // If clicked on an empty cell, start revealing process
            revealBoard(clickRow, clickCol);
        }
     
        return board;
    }
};


/**
529. Minesweeper
Medium

Let's play the minesweeper game (Wikipedia, online game)!

You are given an m x n char matrix board representing the game board where:

    'M' represents an unrevealed mine,
    'E' represents an unrevealed empty square,
    'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
    digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
    'X' represents a revealed mine.

You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').

Return the board after revealing this position according to the following rules:

    If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
    If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
    If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
    Return the board when no more squares will be revealed.
 */
