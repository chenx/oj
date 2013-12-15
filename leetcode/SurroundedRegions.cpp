//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 2/3/2013
// @Last modified: 2/3/2013
//

//
// This works. Passed small test set, and all tests in large test set except the last one. 
// Has run time error for the last input of the largest test set.
// Guess it's stack overflow error. The test input is too large.
//

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        
        int x = board.size();
        int y = board[0].size();
        
        // label those O connected to edge to K.
        for (int i = 0; i < x; ++ i) {
            label(board, i, 0);
            label(board, i, y-1);
        }
        for (int j = 0; j < y; ++ j) {
            label(board, 0, j);
            label(board, x-1, j);
        }
        
        // invert O to X, and recover K to O.
        for (int i = 0; i < x; ++ i) {
            for (int j = 0; j < y; ++ j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'K') board[i][j] = 'O';
            }
        }
    }
    
    // if board[i][j] is O, convert it to K, also convert
    // all connected Os to Ks. Use DFS.
    void label(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] == 'X' || board[i][j] == 'K') return;
        board[i][j] = 'K'; // convert O to K.
        
        int X = board.size();
        int Y = board[0].size();
        if (i > 0 && board[i-1][j] == 'O') label(board, i-1, j);
        if (i < X-1 && board[i+1][j] == 'O') label(board, i+1, j);
        if (j > 0 && board[i][j-1] == 'O') label(board, i, j-1);
        if (j < Y-1 && board[i][j+1] == 'O') label(board, i, j+1);
    }

    // This should work too. Use BFS. But has memory limit exceeded error.
    void label2(vector<vector<char>> &board, int i, int j) {
        if (board[i][j] == 'X' || board[i][j] == 'K') return;

        int X = board.size();
        int Y = board[0].size();

        queue<int> cells;
        cells.push(j), cells.push(i);
        
        while (! cells.empty() ) {
            i = cells.front(), cells.pop();
            j = cells.front(), cells.pop();
            board[i][j] = 'K';
            
            if (i > 0 && board[i-1][j] == 'O') { cells.push(j), cells.push(i-1); } //label(board, i-1, j);
            if (i < X-1 && board[i+1][j] == 'O') { cells.push(j), cells.push(i+1); } //label(board, i+1, j);
            if (j > 0 && board[i][j-1] == 'O') { cells.push(j-1), cells.push(i); } //label(board, i, j-1);
            if (j < Y-1 && board[i][j+1] == 'O') { cells.push(j+1), cells.push(i); } //label(board, i, j+1);
        }
        
    }

};


// Passed small test set. Has error for large input.
class Solution2 {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        
        // label those O connected to edge to K.
        label(board);
        
        int x = board.size();
        int y = board[0].size();
        // invert O to X, and recover K to O.
        for (int i = 0; i < x; ++ i) {
            for (int j = 0; j < y; ++ j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'K') board[i][j] = 'O';
            }
        }
    }
    
    void label(vector<vector<char>> &board) {
        int X = board.size();
        int Y = board[0].size();
        for (int i = 0; i < X; ++ i) {
            if (board[i][0] == 'O') board[i][0] = 'K';
            if (board[i][Y-1] == 'O') board[i][Y-1] = 'K';
        }
        for (int j = 0; j < Y; ++ j) {
            if (board[0][j] == 'O') board[0][j] = 'K';
            if (board[X-1][j] == 'O') board[X-1][j] = 'K';
        }        
        
        int X0 = 0, Y0 = 0;
        
        while (X0 < X) {
            ++ X0, ++ Y0, -- X, -- Y;
            
            // up down
            for (int i = X0; i < X; ++ i) {
                if (board[i][Y0 ] == 'O' && (board[i-1][Y0 ] == 'K' || board[i][Y0-1] == 'K')) board[i][Y0 ] = 'K'; // left
                if (board[i][Y-1] == 'O' && (board[i-1][Y-1] == 'K' || board[i][Y   ] == 'K')) board[i][Y-1] = 'K'; // right
            }
            // down up
            for (int i = X-1; i >= X0; -- i) {
                if (board[i][Y0 ] == 'O' && (board[i+1][Y0 ] == 'K' || board[i][Y0-1] == 'K')) board[i][Y0 ] = 'K'; // left
                if (board[i][Y-1] == 'O' && (board[i+1][Y-1] == 'K' || board[i][Y   ] == 'K')) board[i][Y-1] = 'K'; // right
            }
            
            // left to right
            for (int j = Y0; j < Y; ++ j) {
                if (board[X0 ][j] == 'O' && (board[X0-1][j] == 'K' || board[X0 ][j-1] == 'K')) board[X0 ][j] = 'K'; // top
                if (board[X-1][j] == 'O' && (board[X   ][j] == 'K' || board[X-1][j-1] == 'K')) board[X-1][j] = 'K'; // bottom
            }
            
            // right to left
            for (int j = Y-1; j >= Y0; -- j) {
                if (board[X0 ][j] == 'O' && (board[X0-1][j] == 'K' || board[X0 ][j+1] == 'K')) board[X0 ][j] = 'K'; // top
                if (board[X-1][j] == 'O' && (board[X   ][j] == 'K' || board[X-1][j+1] == 'K')) board[X-1][j] = 'K'; // bottom
            }
                        
        }
    }
    
};

/*

Problem:

 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

 */